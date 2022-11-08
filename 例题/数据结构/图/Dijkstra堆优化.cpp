#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define dd first
#define uu second
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
typedef pair<int,int> PII;      //找一个数组里面的最小值用小根堆就行
int t[N],ne[N],w[N],h[N],idx=0;
int dis[N];
bool book[N];
void add(int from,int to,int wei)
{
    w[++idx]=wei;
    t[idx]=to;
    ne[idx]=h[from];
    h[from]=idx;
}

int dijkstra(int start_node,int end_node)
{
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    memset(dis,0x3f,sizeof dis);
    dis[start_node]=0;
    heap.push({0,start_node});
    book[start_node]=1;
    while(!heap.empty())
    {
        int d=heap.top().dd;        //貌似没用到？
        int u=heap.top().uu;
        if(book[u]) continue;
        book[u]=1;
        for(int i=h[u];~i;i=ne[i])
        {
            int v=t[i];
            if(dis[u]+w[i]<dis[v])
            {
                dis[v]=dis[u]+w[i];
                heap.push({dis[v],v});
            }
        }
    }
    if(dis[end_node]==INF) return -1;
    return dis[end_node];
}

int main()
{
    int n,m;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<dijkstra(1,n)<<endl;
    return 0;
}