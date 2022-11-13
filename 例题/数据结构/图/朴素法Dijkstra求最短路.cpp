#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int n,m;
int g[N][N],dis[N];
bool book[N];

int dijkstra(int start_node,int end_node,int g[N][N])
{
    memset(dis,0x3f,sizeof dis);
    book[start_node]=1;
    dis[start_node]=0;
    for(int i=1;i<=n;i++)
    {
        int u=-1,ans=INF;
        for(int j=1;j<=n;j++)
        {
            if(!book[j]&&(u==-1||dis[u]<dis[j])) u=j;
        }
        book[u]=1;
        for(int j=1;j<=n;j++)
        {
            if(!book[j]&&dis[j]>dis[u]+g[u][j])
                dis[j]=dis[u]+g[u][j];
        }
    }

    if(dis[end_node]==INF) return -1;
    return dis[end_node];
}

int main()
{
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }

    for(int i=1;i<=n;i++) g[i][i]=0;

    cout<<dijkstra(1,n,g)<<endl;

    return 0;
}