#include<iostream>
using namespace std;
const int N=30;
int n,mine_sum[N],pre[N],dp[N];
int ans=0,st;
bool graph[N][N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>mine_sum[i];
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++) cin>>graph[i][j];
    }
    for(int i=n-1;i>=1;i--)
    {
        int maxsum=0,index;
        for(int j=1+1;j<=n;j++)
        {
            if(graph[i][j]&&dp[j]>maxsum)
            {
                maxsum=dp[j];
                index=j;
            }
        }
        if(maxsum>dp[i])
        {
            dp[i]=maxsum+mine_sum[i];
            pre[i]=index;
        }
        if(ans<dp[i])
        {
            ans=dp[i];
            st=i;
        }
    }
    for(int i=st;i<=n;i=pre[i]) cout<<i<<" ";
    cout<<endl<<ans;
    return 0;   //还是用f吧，寄
}