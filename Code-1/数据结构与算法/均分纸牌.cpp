#include<iostream>
using namespace std;
int a[101];
int n,sum=0,ans=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int ave=sum/n;
    for(int i=1;i<n;i++)
    {
        if(a[i]==ave) continue;
        int t=ave-a[i];
        a[i+1]-=t;
        ans++;
    }
    cout<<ans;
}