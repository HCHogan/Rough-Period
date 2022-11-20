#include<iostream>
using namespace std;
const int N=1001,INF=0x3f3f3f3f;

int cnt[N][2];
int n,k,idx,ans;

int main()
{
    cin>>n>>k;
    if(k>=n)
    {
        cout<<"0"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1) cnt[i%k][0]++;
        if(x==2) cnt[i%k][1]++;
    }
    for(int i=0;i<n/k+1;i++)
    {
        ans+=min(cnt[i][0],cnt[i][1]);
    }
    cout<<ans<<endl;
    return 0;
}