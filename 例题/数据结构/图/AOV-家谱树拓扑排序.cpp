#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int to[N],h[N],q[N],ne[N],idx=0;
int du[N];      //入度
int n,d,hh,tt;

int add(int from,int t)
{
    to[++idx]=t;
    ne[idx]=h[from];
    h[from]=idx;
}

int toposort()
{
    for(int i=1;i<=n;i++)
    {
        if(!du[i]) q[tt++]=i;
    }
    while(hh<tt)
    {
        int u=q[hh++];
        cout<<u<<" ";
        for(int i=h[u];~i;i=ne[i])
        {
            int v=to[i];
            if(--du[v]==0)
            {
                q[tt++]=v;
            }
        }
    }
}

int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)
    {
        while(cin>>d,d)
        {
            add(i,d);
            du[d]++;
        }
    }
    toposort();
    return 0;
}