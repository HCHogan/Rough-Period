#include<iostream>
#include<queue>
using namespace std;
const int N=10010;
int tt=-1,hh=0;
int a[N],n,k,q[N];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(hh<=tt&&i-k+1>q[hh]) hh++;
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;
        q[++tt]=i;
        if(i>=k) cout<<a[q[hh]]<<" ";
    }
    cout<<endl;
    hh=0;
    tt=-1;
    for(int i=1;i<=n;i++)
    {
        if(hh<=tt&&i-k+1>q[hh]) hh++;
        while(hh<=tt&&a[q[tt]]<=a[i]) tt--;
        q[++tt]=i;
        if(i>=k) cout<<a[q[hh]]<<" ";
    }
    return 0;
}