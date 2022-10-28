#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int g[N][N],vis[N];
int n,m,ans;

int add(int from,int to,int wei)
{
    g[from][to]=wei;
    g[to][from]=wei;
}

int dfs(int u)
{
    vis[u]=1;
    int d1=0,d2=0;
    for(int i=1;i<=n;i++)
    {
        if(g[u][i]&&!vis[i])
        {
            int d=g[u][i]+dfs(i);
            if(d>d1)
            {
                d2=d1;
                d1=1;
            }
            else if(d>d2)
            {
                d2=d;
            }
        }
    }
    ans=max(ans,d1+d2);
    return d1;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        add(x,y,z);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}