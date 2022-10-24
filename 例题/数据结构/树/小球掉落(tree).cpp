#include<iostream>
#include<cmath>
using namespace std;
int D,n,ans;
bool a[100001];
void drop(int k)
{
    if(pow(2.0,D-1)<=k&&k<pow(2.0,D))
    {
        ans=k;
        return;
    }
    if(a[k])
    {
        a[k]=!a[k];
        drop(2*k+1);
    }
    else
    {
        a[k]=!a[k];
        drop(2*k);
    }
}
int main()
{
    cin>>D>>n;
    for(int i=1;i<=n;i++) drop(i);
    cout<<ans;
    return 0;
}