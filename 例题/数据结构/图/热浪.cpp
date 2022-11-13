#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int h[N],ne[N],we[N],to[N],idx=0;
int n,m,start_node,end_node;
int q[N*2],hh=0,tt=0,dis[N];
bool book[N];

int add(int from,int t,int wei)
{
    we[++idx]=wei;
    to[idx]=t;
    ne[idx]=h[from];
    h[from]=idx;
}

int spfa(int start_node,int end_node)
{
    memset(dis,0x3f,sizeof dis);
    dis[start_node]=0;
    book[start_node]=1;
    q[tt++]=start_node;
    while(hh<tt)
    {
        int u=q[hh++];
        for(int i=h[u];~i;i=ne[i])
        {
            int v=to[i];
            if(dis[v]>dis[u]+we[i])
            {
                dis[v]=dis[u]+we[i];
                if(!book[v])
                {
                    q[tt++]=v;
                    book[v]=1;
                }
            }
        }
    }
    if(dis[end_node]==INF) return -1;
    return dis[end_node];
}

int main()
{
    cin>>n>>m>>start_node>>end_node;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        add(a,b,c);
        add(b,a,c);
    }
    
    cout<<spfa(start_node,end_node)<<endl;
    return 0;
}