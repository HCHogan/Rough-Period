#include<iostream>
//#define lowbit(x) x&-x
using namespace std;
const int N=10010;
int tr[N],int n,op,a,b,q;
int lowbit(int x)
{
    return x&-x;
}
int Asksum(int x)           //区间和
{
    int res=0;
    while(x)
    {
        res+=tr[x];
        x-=lowbit(x);
    }
    return res;
}
int update(int a,int b)         //单点更新
{
    int res=0;
    while(b<=n)
    {
        tr[b]+=a;
        b+=lowbit(b);
    }
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        update(i,t);
    }
    while(q--)
    {
        cin>>op>>a>>b;
        scanf("%d%d%d",&op,&a,&b);
        if(a==1) update(a,b);
        else if(a==2)printf("%d\n",Asksum(b)-Asksum(a-1));
    }
    return 0;
}