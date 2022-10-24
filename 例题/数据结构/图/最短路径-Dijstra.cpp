#include<iostream>
#include<cmath>
#include<cstdio>   //不能用于负边权
using namespace std;
const int N=10001,INF=0x3f3f3f3f;
int g[N][N],map[2][N];
bool book[N];
int node_sum,edge_sum,start_node,end_node;
double dis[N];
double gougu(int a,int b)
{
    return sqrt(double(a*a)+double(b*b));
}
int main()
{
    cin>>node_sum>>edge_sum>>start_node>>end_node;
    memset(book,0,sizeof book);
    for(int i=1;i<=node_sum;i++) cin>>map[0][i]>>map[1][i];
    for(int i=1;i<=node_sum;i++)
    {
        for(int j=1;j<=node_sum;j++)
        {
            if(i==j) g[i][j]=0;
            else g[i][j]=INF; 
        }
    }
    for(int i=1;i<=node_sum;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=g[a][b]=gougu(g[0][a]-g[0][b],g[1][a]-g[1][b]);
    }
    dis[start_node]=0;
    for(int i=1;i<=node_sum-1;i++)
    {
        int t=0;
        double minnum=INF;
        for(int j=1;j<=node_sum;j++)
        {
            if(!book[j]&&dis[j]<=minnum)
            {
                minnum=dis[j];
                t=j;
            }
        }
        int u=t;
        book[u]=1;
        for(int j=1;j<=node_sum;j++)
        {
            if(g[u][j]<INF&&!book[j])
            {
                if(dis[j]>=dis[u]+g[u][j])
                    dis[j]=dis[u]+g[u][j];
            }
        }
    }
    cout<<dis[end_node];
}
