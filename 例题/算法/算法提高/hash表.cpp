#include<iostream>
using namespace std;
const int N=1e6+10;
bool h[N];
int x,n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        h[t]=1;
    }
    cin>>x;
    for(int i=1;i<=n/2;i++)
    {
        if(h[i]&&h[x-i]&&i!=x-i) ans++;
    }
}