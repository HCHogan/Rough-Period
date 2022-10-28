#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int w[N],tod[N],ne[N],idx,h[N],flag[N];     //flag用来标记是否是最短那条路
int d1[N],d2[N],up[N];
int n,m,ans;

int add(int from,int to,int wei)
{
    w[++idx]=wei;
    tod[idx]=to;
    ne[idx]=h[from];
    h[from]=idx;
}

int dfs1(int u,int fa)
{
    d1[u]=0,d2[u]=0;
    for(int i=u;i!=-1;i=ne[i])
    {
        int j=tod[i];
        if(fa==j) continue;
        int d=w[i]+dfs1(j,u);
        if (d>d1[u]) d2[u]=d1[u],d1[u]=d,flag[u]=j;
        else if(d>d2[u]) d2[u]=d;
    }
    return d1[u];       //自下向上
}

int dfs2(int u,int fa)
{
    for(int i=h[u];i!=-1;i=ne[i])   //i是边
    {
        int j=tod[i];
        if(j==fa) continue;
        if(j==flag[u]) up[j]=w[i]+max(up[u],d2[u]);
        else up[j]=w[i]+max(up[u],d2[u]);
        dfs2(j,u);      //自上向下
    }
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        add(x,y,z);
        add(y,x,z);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    int res=INF;
    for(int i=1;i<=n;i++)
    {
        res=min(res,max(up[i],d1[i]));
    }
    cout<<res<<endl;
    return 0;
}