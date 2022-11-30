#include<iostream>
#include<vector>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
//重儿子是以这个为跟节点 字树大小最大的儿子
vector<int> e[N];       //存边
int fa[N],dep[N],son[N],sz[N],top[N];

int n,m;

void dfs1(int u,int father)
{
    fa[u]=father,dep[u]=dep[father]+1;
    for(auto v:e[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[son[u]]<sz[v]) son[u]=v;
    }
}

void dfs2(int u,int t)      //u为当前点 t为表头
{
    top[u]=t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(auto v:e[u])
    {
        if(v==fa[u]||v==son[u]) continue;        //如果是种儿子或者父亲 跳过
        dfs2(v,v);
    }
}

int lca(int u,int v)
{
    while(top[u]!=top[v])   //如果这两个游标到一条重链上的时候 dep低的那个就是LCA
    {                       //20221127不是很能理解
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];       //直接跳到这条重连头的fa
    }
    return dep[u]<dep[v]?u:v;
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
    dfs1(1,0);
}