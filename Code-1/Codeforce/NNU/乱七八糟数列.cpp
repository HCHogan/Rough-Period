#include<iostream>
using namespace std;
int a,b,n;
int calc(int x)
{
    if(x==1) return b;
    else if(x==0) return a;
    else if(x==2) return a^b;
    else return calc(x-3);
}

int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        cin>>a>>b>>n;
        n%=3;
        int ans=calc(n);
        cout<<ans<<endl;
    }
}