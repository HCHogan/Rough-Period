#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    float ans;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n%2==0)
    {
        ans=(a[n/2]+a[n/2+1]+0.0)/2;
    }
    else
    {
        ans=a[(n+1)/2]+0.0;
    }
    cout<<ans;
}