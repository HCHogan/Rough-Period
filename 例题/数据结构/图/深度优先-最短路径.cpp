#include<iostream>
using namespace std;
const int N=10001,INF=0x3f3f3f3f;
int min_distance=INF,g[N][N];
int node_sum,edge_sum,start_node,end_node;
bool vis[N];
void dfs(int cur,int path_length)
{
    if(path_length>min_distance) return;
    if(cur=end_node)
        min_distance=path_length;
    for(int i=1;i<=node_sum;i++)
    {
        if(g[cur][i]<INF-1&&!vis[i])
        {
            vis[i]=1;
            dfs(i,path_length+g[cur][i]);
            vis[i]=0;
        }
    }
}
int main()
{
    cin>>node_sum>>edge_sum;
    for(int i=1;i<=node_sum;i++)
        for(int j=1;j<=node_sum;j++)
        {
            if(i==j) g[i][j]=0;
            else g[i][j]=INF;
        }
    for(int i=1;i<=edge_sum;i++)
    {
        int x,y,z;
        g[x][y]=z;
    }
    memset(vis,0,sizeof vis);
    vis[start_node]=1;
    dfs(start_node,0);
    cout<<min_distance;
    return 0;
}