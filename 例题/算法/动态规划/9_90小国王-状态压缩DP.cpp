#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int f[N][N][N];  //f[i][j][a]表示第i行已经放了j个国王 这排状态为a时的方法数
int n,m,idx;
int s[N],c[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=(1<<n);i++)
    {
        if(!(i&i>>1)) 
        {
            s[++idx]=i;
            for(int j=1;j<=n;j++)
                if(i>>j&1) c[idx]++;
        }
    }
    f[0][0][0]=1;

    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=m;i++)
        {
            for(int a=1;a<=idx;a++)
            {
                int cnt=c[a];
                int aa=s[a];
                for(int b=1;b<=idx;b++)
                {
                    int bb=s[b];
                    if(!(aa&bb)&&!(aa&bb>>1)&&!(aa&bb<<1)&&j>=cnt)
                    {
                        f[i][j][aa]+=f[i-1][j-cnt][bb];
                    }
                }
            }
        }
    }
    
    cout<<f[n+1][m][0]<<endl;
    
    return 0;
}