#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int tr[N],n;

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