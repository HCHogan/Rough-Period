#include<iostream>
using namespace std;
const int N=10010;
int h[N],n,cnt;
void down(int u)
{
    int t=u;
    if(u*2<=cnt&&h[t]<h[u*2]) t=u*2;
    if(u*2+1<=cnt&&h[t]<h[u*2+1]) t=u*2+1;
    if(t!=u)
    {
        swap(h[u],h[t]);
        down(t);
    }
    return;
}
int test01()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=n/2;i;i--) down(i);
    cnt=n;
    for(int i=n;i>1;i--)
    {
        swap(h[i],h[1]);
        cnt--;
        down(1);
    }
    for(int i=1;i<=n;i++) cout<<h[i];
}

int main()
{
    test01();
    return 0;
}