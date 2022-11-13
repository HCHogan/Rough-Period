#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int n,m,f[N][10],a[N],cnt=0;      //a[i]存各位数字   f[i][j]表示一共i位 
int a,b;                            //以j最高位的数字一共有多少个

int init()
{
    for(int i=0;i<=9;i++)
    {
        f[1][i]=1;
    }
    for(int k=2;k<=n;k++)
    {
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                if(abs(i-j)>=2)
                    f[k][i]+=f[k-1][j];
            }
        }
    }
    return 0;
}

int dp(int x)
{
    if(!x) return 0;
    int last=-2,res=0;
    for(int i=cnt;i>=1;i--)
    {
        int now=a[i];
        for(int j=(i==cnt);j<now;j++)
        {
            if(abs(j-last)>=2) res+=f[i][j];
        }
        if(abs(now-last<2)) break;      //以当前这个为last继续搜 无意义 因为last和last的last已经不符合定义了
        last=now;
        if(i==1) res++;
    }
    for(int i=1;i<cnt;i++)
    {
        for(int j=1;j<=9;j++)
            res+=f[i][j];
    }
    return res;
}

int main()
{
    cin>>n;
    cin>>m;
    int l,r;
    cin>>l>>r;
    init();
    dp(m);
    cout<<dp(r)-dp(l-1)<<endl;

    return 0;
}