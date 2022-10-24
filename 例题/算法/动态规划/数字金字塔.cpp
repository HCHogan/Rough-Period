#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10001][10001],f[10001][10001],n,ans;
const int INF=0x3f3f3f3f;
int main()       //f[i][j]是在f[i][j]处到顶部所有路径中最短路径的长度
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++) cin>>a[i][j];
    }
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
        }
    }
    ans=-INF;
    for(int j=1;j<=n;j++)
    {
        if(a[n][j]>ans) ans=a[n][j];
    }
    cout<<ans;
}