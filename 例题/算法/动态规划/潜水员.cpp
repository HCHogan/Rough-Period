#include<iostream>
using namespace std;
const int N=10001;
int n,m,k;
int f[N][N];
int main()
{
    cin>>k;
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    while(k--)
    {
        int ox,ni,wei;
        cin>>ox>>ni>>wei;
        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                f[i][j]=min(f[i][j],f[max(0,i-ox)][max(0,j-ni)]+wei);
            }
        }
    }
    return 0;
}