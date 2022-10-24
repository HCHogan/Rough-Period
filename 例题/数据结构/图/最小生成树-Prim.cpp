#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int g[N][N],minw[N],book[N];
//minw[i]表示已经访问过的点构成的树到第i个点最短距离
//而在dijkstra算法中dis[i]表示从起点到第i个点最短距离
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        g[x][y]=z;
        //g[y][x]=z;
    }

    memset(minw,0x3f,sizeof minw);

    minw[1]=0;
    for(int i=1;i<=n;i++)
    {
        int k=0;
        for(int j=1;j<=n;j++)
        {
            if(!book[j]&&minw[j]<minw[k]) k=j;
        }
        book[k]=1;
        for(int j=1;j<=n;j++)
        {
            if(!book[j]&&g[k][j]<minw[j]) minw[j]=g[k][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=minw[i];
    }
    cout<<ans<<endl;
    return 0;
}