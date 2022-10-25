#include<iostream>     //完全背包问题就是一个东西有无限多个，01背包问题是每个物品只有一个
using namespace std;
int n,m,t;
int f[101][101];
int a[101];
int main()    //二维版
{
    for(int i=1;i<=n;i++)
    {
        int value,space;
        cin>>value>>space;
        for(int j=1;j<=n;j++)
        {
            if(j>=space) f[i][j]=max(f[i-1][j],value+f[i][j-space]);
            else f[i][j]=f[i-1][j];
        }
    }
    cout<<f[n][m];
}
int main2()
{
    for(int i=1;i<=n;i++)
    {
        int value,space;
        for(int j=space;j<=m;j++)
            a[j]=max(value+a[j-space],a[j]);
    }
    cout<<a[m];
    return 0;
}