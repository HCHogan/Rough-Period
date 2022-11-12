#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int tr[N],levelsum[N],n,m;

int lowbit(int x)
{
    return x&-x;
}

void update(int x,int t)
{
    while(x<=n)
    {
        tr[x]+=t;
        x+=lowbit(x);
    }
}


int asksum(int x)
{
    int res=0;
    while(x)
    {
        res+=tr[x];
        x-=lowbit(x);
    }
    return res;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        x++;
        levelsum[asksum(x)]++;
        update(x,1);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<levelsum[i]<<" ";
    }
    return 0;
}