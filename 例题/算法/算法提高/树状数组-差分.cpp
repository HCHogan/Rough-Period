#include<iostream>
#include<cstring>
//#define lowbitx(x) x&-x
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int n,op,a,b,q;
long long tra[N];
int lowbit(int x)
{
    return x&-x;  
}
void update(int i,int x)
{
    while(i<=n)
    {
        tra[i]+=x;
        i+=lowbit(i);
    }
}
long long AskSum(int i)
{
    long long res=0;
    while(i)
    {
        res+=tra[i];
        i-=lowbit(i);
    }
    return res;
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        update(i,x),update(i+1,-x);
    }
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='C')
        {
            int l,r,x;
            cin>>l>>r>>x;
            update(l,x),update(r+1,-x);
        }
        if(c=='Q')
        {
            int i;
            cin>>i;
            printf("%d",AskSum(i));
        }
    }
    return 0;
}