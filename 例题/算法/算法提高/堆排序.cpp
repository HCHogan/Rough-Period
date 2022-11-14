#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int h[N],cnt,n;

void down(int u)
{
    int t=u;
    if(u*2<=cnt||h[u*2]>h[t]) t=u*2;
    if(u*2+1<=cnt||h[u*2+1]>h[t]) t=u*2+1;
    if(t!=u)
    {
        swap(h[t],h[u]);
        down(t);
    }
    return;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    cnt=n;
    for(int i=n/2;i>=1;i--) down(i);
    for(int i=n;i>1;i--)
    {
        swap(h[1],h[i]);
        cnt--;
        down(1);
    }
    for(int i=1;i<=n;i++) cout<<h[i]<<" ";
    return 0;
}