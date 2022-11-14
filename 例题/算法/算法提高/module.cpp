#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int h[N],cnt,n;

void down(int u)
{
    int t=u;
    if(u*2<=cnt&&h[u*2]<h[t]) t=u*2;
    if(u*2+1<=cnt&&h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t)
    {
        swap(h[u],h[t]);
        down(t);
    }
    return;
}

void up(int u)
{
    while(u/2&&h[u/2]>h[u])
    {
        swap(h[u],h[u/2]);
        up(u/2);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[++cnt];
        up(cnt);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<h[1]<<" ";
        h[1]=h[cnt--];
        down(1);
    }
    return 0;
}
