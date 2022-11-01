#include<iostream>
using namespace std;
//数位dp的特点 让你输出一定范围内满足某种性质的一些数 一般范围都很大
//要求a到b 求dp(b)-dp(a-1)
const int N=10010,INf=0x3f3f3f3f;
int f[N][10];       //f[i][j]表示一共有i位 且最高位是j的数的个数（草 最高位 我是傻逼）
int a,b,n;

void init()
{
    for(int i=0;i<=9;i++) f[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                if(abs(j-k)>=2) f[i][j]+=f[i-1][k];
            }
        }
    }
}

int dfs(int x)
{
    int a[N],cnt=0;
    while(x) a[++cnt]=x%10,x/=10;
    int last=-2,res=0;
    for(int j=cnt;j>=1;j--)
    {
        int now=a[j];
        
    }
}

int main()
{
    cin>>n>>a>>b;
    init();
}