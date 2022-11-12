#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int tr[N],n,m;

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

int ask(int x)
{
    int res=0;
    while(x)
    {
        res+=tr[x];
        x-=lowbit(x);
    }
    return res;
}

int insert(int x,int t)
{
    update(x,t);
    update(x+1,-t);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,t;
        cin>>x>>t;
        insert(x,t);
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        cout<<ask(x)<<endl;
    }
    return 0;
}