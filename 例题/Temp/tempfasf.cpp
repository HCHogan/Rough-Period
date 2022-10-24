#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int g[N][N],dis[N],pre[N];
bool book[N];
int node_sum,edge_sum,start_node,end_node;
int main()
{
    cin>>node_sum>>edge_sum>>start_node>>end_node;
    for(int i=1;i<=node_sum;i++)
        for(int j=1;j<=node_sum;j++)
            g[i][j]=INF;
    memset(dis,0x3f,sizeof dis);
    memset(book,0,sizeof book);
    for(int i=1;i<=edge_sum;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=z;
    }
    int t=0,minnum=INF;
    dis[start_node]=0;
    book[start_node]=1;
    for(int i=1;i<=node_sum-1;i++)
    {
        minnum=INF;
        for(int j=0;j<node_sum;j++)
        {
            if(dis[j]<minnum&&!book[j])
            {
                minnum=dis[j];
                t=j;
            }
        }
        int u=t;
        book[u]=1;
        for(int v=0;v<node_sum;v++)
        {
            if(dis[u]+g[u][v]<dis[v])
            {
                dis[v]=dis[u]+g[u][v];
                pre[v]=u;
            }
        }
    }
    if(dis[end_node]>INF-1) cout<<"no answer";
    else  cout<<dis[end_node];
    return 0;
}