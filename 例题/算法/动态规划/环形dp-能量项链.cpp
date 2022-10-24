#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int f[N][N];
int n,a[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }

    for(int len=3;len<=n;len++)     //融合要3个数 所以len最小是3
    {
        for(int l=1;l+len-1<2*n;l++)
        {
            int r=l+len-1;
            for(int k=l+1;k<r;k++)
            {
                f[l][r]=max(f[l][r],f[l][k]+f[k][r]+a[l]*a[k]*a[r]);
            }
        }
    }

    int maxv=-INF;
    for(int i=1;i<=n;i++)
    {
        maxv=max(maxv,f[i][i+n]);
    }
    cout<<maxv<<endl;
    return 0;
}