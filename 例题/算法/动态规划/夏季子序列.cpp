#include<iostream>
using namespace std;
const int N=10001,INF=0x3f3f3f3f;
int n,a[N][3],ans=-INF;
int main()
{
    cin>>n;
    memset(a,0,sizeof a);
    for(int i=1;i<=n;i++) cin>>a[0][i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=i;j++)
        {
            int flag;
            if(a[1][j]>ans)
            {
                a[1][i]=a[1][j]+1;
                a[2][i]=j;
            }
        }
    }
}