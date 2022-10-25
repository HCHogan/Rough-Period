#include<iostream>
using namespace std;
const int N=10010;
int m,n,a[N],s[N];
int main()
{
    cin>>n>>m;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]+s[i-1];
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1];
    }
    return 0;
}