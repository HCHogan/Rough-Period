#include<iostream>
using namespace std;
const int N=10001;
int node_sum,edge_sum,ans=0;
bool g[N][N];
int main()
{
    cin>>node_sum>>edge_sum;
    memset(g,0,sizeof g);
    for(int i=1;i<=edge_sum;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x][y]=1;
    }
    for(int k=1;k<=node_sum;k++)
        for(int i=1;i<=node_sum;i++)
            for(int j=1;j<=node_sum;j++)
                if(i!=k&&j!=k&&i!=j)
                    g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);
    for(int i=1;i<=node_sum;i++)
    {
        int lesssum=0,moresum=0;
        for(int j=1;j<=node_sum;j++)
        {
            if(g[i][j]) moresum++;
            if(g[j][i]) lesssum++;
        }
        if((node_sum+1)/2<lesssum||(node_sum+1)/2>moresum) ans++;
    }
    cout<<ans;
    return 0;
}