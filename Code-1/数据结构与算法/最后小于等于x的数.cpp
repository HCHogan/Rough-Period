#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[100000]={-1};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        int x;
        cin>>x;
        int L=0,R=n+1;
        while(L+1!=R)
        {
            int mid=(L+R)>>1;
            if(a[mid]>x) R=mid;
            else L=mid;
        }
        cout<<a[L]<<endl;
    }
}