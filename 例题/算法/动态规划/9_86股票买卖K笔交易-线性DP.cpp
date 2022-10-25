#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int w[N],f[N][N][2];    //f[i][j][1]表示第i天买卖第j次 此时手里有票最大价值
                        //f[i][j][0]表示无票    
int n,k;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>w[i];
    //边界赋值技巧：有意义赋值有限值 非法赋INF
    for(int i=1;i<=k;i++) f[0][i][1]=-INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]+w[i]);
            f[i][j][1]=max(f[i-1][j-1][0]-w[i],f[i-1][j][1]);
        }
    }
    cout<<max(f[n][k][1],f[n][k][0])<<endl;
    return 0;
}