#include<iostream>
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N=1e6+10;

long long n,w[N],ans,t;

struct node
{
    int l,r;
    long long sum;
}tr[N*4];

void build(int p,int l,int r)
{
    tr[p].l=l;
    tr[p].r=r;
    tr[p].sum=w[l];
    if(l==r) return;
    int m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    tr[p].sum=tr[lc].sum+tr[rc].sum;
    return;
}

void find(int p,long long t)
{
    if(tr[p].sum<t)
    {
        ans+=(tr[p].r-tr[p].l+1)*(tr[p].r-tr[p].l+2)/2;
        return;
    }
    else
    {
        if((lc)<4*n) find(lc,t);
        if((rc)<4*n) find(rc,t);
        return;
    }
}

int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1,1,n);
    find(1,t);
    cout<<ans<<endl;
    return 0;
}