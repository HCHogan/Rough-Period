//21220513 杨圣涵
#include<iostream>
#include<cmath>
using namespace std;

#define MOD 100003
typedef long long ll;

ll n,m;

ll qpow(ll a, ll n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a % MOD;
    else
    {
        ll temp = qpow(a, n / 2) % MOD;
        return temp * temp % MOD;
    }
}

int main()
{
    cin>>m>>n;
    ll a=qpow(m,n);
    ll b=(m*qpow(m-1,n-1))%MOD;
    cout<<a-b<<endl;
    return 0;
}