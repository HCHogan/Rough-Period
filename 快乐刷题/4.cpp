//21220513杨圣涵
#include<iostream>
using namespace std;

int a,b,T;
long long n;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>n;
        if(n%3==1) cout<<b<<endl;
        else if(n%3==0) cout<<a<<endl;
        else cout<<(int)(a^b)<<endl;
    }
    return 0;
}