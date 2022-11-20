#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

long long a,ans[N];
int hh=-1;

int main()
{
    cin>>a;
    while(a>1)
    {
        ans[++hh]=a;
        cout<<a<<" ";
        a=(a>>1)|1;
    }
    cout<<endl<<0<<" ";
    while(hh) cout<<ans[hh--]<<" ";
}