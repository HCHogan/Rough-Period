#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100000]={-1};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    int L=0,R=n+1;
    while(L+1!=R)
    {
        int mid=(L+R)>>1;
        if(a[mid]<x) L=mid;
        else R=mid;
    }
    if(R>n) cout<<-1;
    else cout<<R<<endl;
}