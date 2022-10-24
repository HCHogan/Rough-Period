#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int f[N][N],g[N][N];
int s[N],a[N];
//f[L,R]表示吧从L到R合并成一堆的最小代价
int main()
{
    int n;
    cin>>n;
    memset(f,0,sizeof f);
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=2*n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l+len-1<=2*n;l++)        //吧原数组复制一遍 环转换为链
        {
            int r=l+len-1;
            for(int k=l;k<=r;k++)
            {
                f[l][r]=max(f[l][r],f[l][k]+f[k][r]+s[r]-s[l-1]);
                g[l][r]=min(g[l][r],g[l][k]+g[k][r]+s[r]-s[l-1]);
            }
        }
    }

    int maxv=-INF,minv=INF;

    for(int i=1;i<=n;i++)
    {
        maxv=max(maxv,f[i][i+n]);
        minv=min(minv,g[i][i+n]);
    }

    cout<<maxv<<endl<<minv<<endl;
    return 0;
}