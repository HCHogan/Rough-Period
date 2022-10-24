#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e8;
int work(int n)
{
    if(n==2) return 1;
    if(n==1) return 1;
    return work(n-1)+work(n-2);
}

int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a=work(n);
    int b=work(m);
    if(a<b) swap(a,b);
    int ans=gcd(a,b);
    ans=ans%N;
    cout<<ans;
}