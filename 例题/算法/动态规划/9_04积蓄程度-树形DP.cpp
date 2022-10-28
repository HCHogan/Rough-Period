#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int e[N],w[N],h[N],ne[N];
int n,m,idx;

int add(int from,int to,int wei)
{
    e[++idx]=to;
    w[idx]=wei;
    ne[idx]=h[from];
    h[from]=idx;
}

int dfs(int u,int fa)
{
   int sum=0;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(j==fa) continue;
        sum+=min(w[i],dfs(j,u));
    }
    return sum;
}

int dfs1(int u,int fa)
{

}

int dfs2(int u,int fa)
{

}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        add(x,y,z);
        add(y,x,z);
    }
    int ans=0;
    for(int i=1;i<=n;i++)       //超时
    {
        ans=max(ans,dfs(i,-1));
    }
    cout<<ans<<endl;
    return 0;
}