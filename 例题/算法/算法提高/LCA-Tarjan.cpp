#include<iostream>
#include<vector>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
//tarjan算法是离线算法 需要先知道所有询问 利用并查集维护祖先节点
//递归 4个时机 入下回离
int fa[N],vis[N],ans[N];
//fa并查集 vis记录是否经过 ans记录答案
int n,m;

vector<pair<int,int>> query[N];
vector<int> e[N];

int init()
{
    for(int i=1;i<=n;i++) fa[i]=i;
    return 0;
}

int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]); 
}

int tarjan(int u)
{
    vis[u]=true;
    for(auto v:e[u])
    {
        tarjan(v);
        fa[v]=u;        //出来的时候连边
    }
    for(auto v:query[u])
    {
        int to=v.first,num=v.second;
        if(vis[to]) ans[num]=find(to);      //搜到这个的时候上面还没连所以一定是LCA
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        int from,to;
        cin>>from>>to;
        e[from].push_back(to);
    }
    for(int i=1;i<=m;i++)
    {
        int from,to;
        cin>>from>>to;
        query[from].push_back({to,i});
        query[to].push_back({from,i});
    }
    tarjan(1);
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}