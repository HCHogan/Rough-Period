#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
bool vis[N];
int node_sum,edge_sum,end_node;
int dis[N],g[N][N];
int main()
{
    scanf("%d%d",node_sum,edge_sum);
    memset(g,0,sizeof g);
    for(int i=1;i<=node_sum;i++)
        for(int j=1;j<=node_sum;j++)
        {
            if(i==j) g[i][j]=0;
            else g[i][j]=INF;
        }
    for(int i=1;i<=edge_sum;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=g[y][x]=z;
    }
    cin>>end_node;
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    vis[1]=1,dis[1]=0;
    for(int i=1;i<=node_sum;i++)
    {
        int minnum=INF,t;
        for(int j=1;j<=node_sum;j++)
        {
            if(g[i][j]<=minnum)
            {
                minnum=g[i][j];
                t=j;
            }
        }
        int u=t;
        vis[u]=1;
        for(int v=1;v<=node_sum;v++)
        {
            if(dis[v]>dis[u]+g[u][v]&&!vis[v])
            {
                dis[v]=dis[u]+g[u][v];
            }
        }
    }
    printf("%d",dis[end_node]);
    return 0;
}