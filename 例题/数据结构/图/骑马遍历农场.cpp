#include<iostream>
using namespace std;
const int N=10001,INF=0x3f3f3f3f;
int edge_sum,node_sum;
int g[N][N],path[N],cnt=0,du[N];
int maxnode,ibegin;
int dfs(int i)          //一条边不能重复走
{
    for(int j=1;i<=maxnode;j++)
    {
        if(g[i][j])
        {
            g[i][j]--;              //把路踏平
            g[j][i]--;              //无向图
            dfs(j);
        }
    }
    path[++cnt]=i;
}
int main()
{
    cin>>node_sum>>edge_sum;
    memset(du,0,sizeof du);
    memset(g,0,sizeof g);
    for(int i=1;i<=edge_sum;i++)
    {
        int x,y;
        cin>>x>>y;
        du[x]++;
        du[y]++;
        maxnode=max(maxnode,max(x,y));
        ibegin=min(ibegin,min(x,y));

    }
    int istart=ibegin;
    for(int i=ibegin;i<=maxnode;i++)
    {
        if(du[i]%2==1)
        {
            istart=i;
        }
    }
    dfs(istart);
    for(int i=cnt;i>=1;i++) cout<<path[i];
    return 0;
}