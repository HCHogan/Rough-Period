#include<iostream>
using namespace std;
const int N=10001;
bool g[N][N],vis[N];
int n,e,du[N],istart,k,cnt=0,cir[N],k=0;
int dfs(int i)
{
    for(int j=1;j<=e;i++)
    {
        if(g[i][j]&&!vis[i])
        {
            vis[j]=1;
            dfs(j);
        }
    }
    cir[++cnt]=i;
}
int main()
{
    cin>>n>>e;
    memset(g,0,sizeof g);
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=g[b][a]=1;          //无向图
        du[a]++;
        du[b]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(du[i]%2)
        {
            k++;
            istart=1;
        }
    }
    if(k==2||k==0)
    {
        dfs(istart);
        for(int i=1;i<=n;i++)
            cout<<cir[i]<<" ";
        cout<<endl;
    }
    else cout<<-1;
    return 0;
}