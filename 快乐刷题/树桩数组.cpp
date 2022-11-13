#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int tr[N],n,m,x,t;

int lowbit(int x)
{
    return x&-x;
}

void update(int x,int t)
{
    while(t<=n)
    {
        tr[x]+=t;
        x+=lowbit(x);
    }
}

int ask(int x)
{
    int t=0;
    while(x>=1)
    {
        t+=tr[x];
        x-=lowbit(x);
    }
}
 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>t;
        update(x,t);
    }

    cin>>m;
    for(int i=1;i<=m;i++)
    {

    }
    return 0;
}