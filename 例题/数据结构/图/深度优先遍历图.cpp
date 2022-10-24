#include<iostream>
using namespace std;
const int N=10001;
int g[N][N],f[N];
int n,m;    //n为节点数m为边数
void dfs(int i)     //本质还是深搜
{
    cout<<i;
    for(int j=1;j<=n;j++)
    {
        if(g[i][j]&&!f[j]) dfs(j);
    }
}
int main()
{
    cin>>n>>m;
    memset(g,0,sizeof f);
    memset(f,0,sizeof f);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=g[b][a]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!f[i]) dfs(i);
    }
    return 0;
}