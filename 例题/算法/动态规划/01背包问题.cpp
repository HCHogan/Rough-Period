#include<iostream>
using namespace std;
int n,m;                    //n件物品，背包容量为m
int f[101][101],g[101];
int main()      //二维版
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int space,value;
        cin>>space>>value;
        for(int j=1;j<=m;j++)
        {
            if(j>=space) f[i][j]=max(f[i-1][j],value+f[i-1][j-space]);
            else f[i][j]=f[i-1][j];
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
int main2()      //一维优化  为了防止前面的被改 所以倒着遍历
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int space,value;
        cin>>space>>value;
        for(int j=m;j>=space;j++)
            g[j]=max(g[j],value+g[j-space]);
    }
    cout<<g[m];
}