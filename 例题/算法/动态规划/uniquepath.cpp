#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int f[N][N],n,m;      //f[i][j]表吃走到f[i][ij]一共要用多少步

int main()
{
    cin>>n>>m;
    f[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1];
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}