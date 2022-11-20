#include<iostream>
using namespace std;
const int N=2e5+10;

typedef long long ll;

ll a[N],s[N],t;
ll n,cnt;

int main()
{
    cin>>n>>t;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            if(s[j]-s[i]<t) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}