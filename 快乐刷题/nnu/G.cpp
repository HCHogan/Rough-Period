#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;

int T,n;
int a[N];
int ans;

int main()
{
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        memset(a,0,sizeof a);
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int p=upper_bound(a+1,a+n+2,0)-a;
        for(int j=n,i=p-1;j>=p&&i>=1;j--,i--)
        {
            ans+=a[i]+a[j];
        }
        
        cout<<ans<<endl;
    }

}