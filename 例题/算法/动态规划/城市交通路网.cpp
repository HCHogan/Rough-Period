#include<iostream>
using namespace std;
const int N=10001,INF=0x3f3f3f3f;
int g[N][N],f[N],pre[N];
int main()
{
    int n;
    memset(f,INF,sizeof f);
    memset(g,0,sizeof g);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>g[i][j];
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(g[i][j]>0&&f[j]<INF&&f[i]>f[j]+g[i][j])
            {
                f[i]=f[j]+g[i][j];
                pre[i]=j;
            }
        }
    }
    printf("minlength=%d\n",f[1]);
    int i=1;
    while(i)
    {
        printf("%d",i);
        i=pre[i];
    }
    return 0;
}