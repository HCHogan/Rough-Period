#include<iostream>
#include<algorithm>
using namespace std;
const int N=20010;
int a[N];
int ans=0;
int main()
{
    int n,alt;
    cin>>n>>alt;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int i=1;
    while(alt)
    {
        if(alt<a[i])
        {
            ans++;
            break;
        }
        else{
            alt-=a[i];
            ans++;
            i++;
        }
    }
    cout<<ans;
}