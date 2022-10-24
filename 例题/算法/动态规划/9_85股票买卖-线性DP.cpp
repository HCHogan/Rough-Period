#include<iostream>
using namespace std;
const int N=10010;

int f[N];
int stock[N];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>stock[i];
    stock[0]=stock[1];
    for(int i=1;i<=n;i++)
    {
        f[i]=max(f[i-1],f[i-1]+stock[i]-stock[i-1]);
    }
    cout<<f[n]<<endl;
    return 0;
}