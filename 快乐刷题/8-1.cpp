//21220513 杨圣涵
#include<iostream>
#include<cmath>
using namespace std;

#define MOD 100003
typedef long long ll;

ll n,m;

ll qpow(ll a, ll n){
    ll ans = 1;
    while(n){
        if(n&1)        
            ans = (ans*a)%MOD;  
        a = (a*a)%MOD;        
        n >>= 1;       
    }
    return ans%MOD;
}

int main()
{
    cin>>m>>n;
    if(m==1)
    {   
        cout<<'1'<<endl;
        return 0;
    }
    if(n==1)
    {
        cout<<m<<endl;
        return 0;
    }
    ll a=qpow(m,n);
    ll b=(m*qpow(m-1,n-1))%MOD;
    cout<<(a-b)%MOD<<endl;
    return 0;
}