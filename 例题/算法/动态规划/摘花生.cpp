#include<iostream>
using namespace std;
const int N=100;
int n,f[N][N],T;
int main()
{
    cin>>T;
    while(T--)
    {
        memset(f,0,sizeof f);
        int r,c;
        cin>>r>>c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                int x;
                cin>>x;
                f[i][j]+=max(f[i-1][j],f[i][j-1])+x;
            }      //确实 我是傻逼
        cout<<f[r][c];
    }
}
// 状态转移 分组