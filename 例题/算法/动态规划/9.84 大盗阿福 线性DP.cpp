#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int T,f[2][N],n;        //w[0][i]表示从1选到i 不选i的情况下价值最大值
                        //w[1][i]表示从1选到i 选i的情况下价值最大值
int w[N],g[N];

int main()
{
    cin>>T;
    while(T--)
    {
        memset(f,0,sizeof f);
        memset(w,0,sizeof w);
        cin>>n;
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=n;i++) f[i][1]=w[i];
        for(int i=1;i<=n;i++)   //二维 分不偷和偷[CoolGuy]  分类转移（好）
        {
            f[i][1]=f[i-1][0]+w[i];
            f[i][0]=max(f[i-1][1],f[i-1][0]);
        }
        g[0]=0,g[1]=w[1];       //一维optimized         分布转移
        for(int j=2;j<=n;j++)
        {
            g[j]=max(g[j-1],g[j-2]+w[j]);
        }
        cout<<max(f[n][0],f[n][1])<<endl;
    }
    return 0;
}