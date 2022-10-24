#include<iostream>
#include<cmath>
using namespace std;
int cnt=0;
bool isPrime(int i)
{
    if(i==1) return 0;
    if(i==2) return 1;
    for(int j=2;j<=sqrt(i);j++) if(i%j==0) return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-2;i++) 
        if(isPrime(i)&&isPrime(i+2))
        {
            cnt++;
            cout<<i<<" "<<i+2<<endl;
        }
    if(cnt==0) cout<<"empty";
    return 0;
}