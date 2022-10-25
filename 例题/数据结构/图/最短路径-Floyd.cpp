#include<iostream>
#include<cmath>
using namespace std;
const int N=10001;
int a[2][N];
double g[N][N];
int edge_sum,node_sum,node_start,node_end;
int main()
{
    cin>>node_sum;
    memset(g,0x7f,sizeof g);
    for(int i=1;i<=node_sum;i++)
    {
        cin>>a[0][i]>>a[1][i];
    }
    cin>>edge_sum;
    for(int i=1;i<=edge_sum;i++)
    {
        int at,bt;
        cin>>at>>bt;
        double dx=pow(double(a[0][at]-a[0][bt]),2);
        double dy=pow(double(a[1][at]-a[1][bt]),2);
        double dis=sqrt(dx+dy);
        g[at][bt]=g[bt][at]=dis;
    }
    for(int k=1;k<=node_sum;k++)
    {
        for(int i=1;i<=node_sum;i++)
        {
            for(int j=1;j<=node_sum;j++)
            {
                if(i!=k&&j!=k&&i!=j&&g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    cin>>node_start>>node_end;
    cout<<g[node_start][node_end];
    return 0;
}