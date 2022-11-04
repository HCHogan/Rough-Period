#include<iostream>
using namespace std;
const int N=34,INF=0x3f3f3f3f;
int a[N],f[N][N];       //f[i][j]表示一共i位放j个1的组合数
int l,r,k,cnt,b;

void init()
{
    for(int i=0;i<N;i++) f[i][0]=1;
    for(int i=1;i<=N;i++)
        for(int j=1;j<N;j++)
            f[i][j]=f[i-1][j]+f[i-1][j-1];
    return;
}

int dp(int n)
{
    if(!n) return 0;
    int res=0;
    int cnt=0;
    while(n)
    {
        a[++cnt]=n%b;
        n/=b;
    }
    int last=0;
    for(int i=cnt;i>=1;i++)
    {
        int x=a[i];
        if(x)
        {
            res+=f[i-1][k-last];
            if(x>1)                         //如果第i位大于1
            {
                res+=f[i-1][k-last-1];      //第i位放1的情况
                break;                      //之后第i位都大于1 无需讨论
            }
            else
            {
                last++;                     //如果第i位是一 无法直接判断 继续枚举下一位
                if(last>k) break;
            }
        }
        if(i==1&&last==k) res++;
    }
    return res;
}

int main()
{
    cin>>l>>r>>k>>b;
    init();
    cout<<dp(r)-dp(l-1)<<endl;
    return 0;
}