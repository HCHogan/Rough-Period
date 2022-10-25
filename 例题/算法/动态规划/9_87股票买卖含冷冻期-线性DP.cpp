//冷冻期为1天
#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int f[N][2];        //f[i][0]表示第i天手里没有股票 最大价值 1表示有
int n,w[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];

    for(int i=1;i<=n;i++)
    {
        f[i][1]=max(f[i-1][1],f[i-2][0]-w[i]);
        f[i][0]=max(f[i-1][0],f[i-1][1]+w[i]);
    }

    cout<<max(f[n][1],f[n][0])<<endl;
    
    return 0;
}