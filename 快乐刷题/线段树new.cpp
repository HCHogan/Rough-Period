#include<iostream>
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

struct node
{
    int l,r;
    int sum,add;
}tr[N*4];

int w[N];

int pushup(int p)
{
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}

int pushdown(int p)
{
    tr[lc].sum+=tr[p].add*(tr[lc].r-tr[lc].l+1);
    tr[rc].sum+=tr[p].add*(tr[rc].r-tr[lc].l+1);
    tr[lc].add+=tr[p].add;
    tr[rc].add+=tr[p].add;
    tr[p].add=0;
}

void build(int p,int l,int r)
{
    tr[p].l=l;
    tr[p].r=r;
    tr[p].sum=w[l];
    if(l==r) return;
    int m=l+r>>1;
    if(l<m) build(lc,l,m);
    if(m<=r) build(rc,m+1,r);
    pushup(p);
}

int update(int p,int x,int y,int k)
{
    if(x<=tr[p].l&&tr[p].r<=y)
    {
        tr[p].add+=k;
        tr[p].sum+=k*(tr[p].r-tr[p].l+1);
        return;
    }
    int m=x+y>>1;
    pushdown(p);
    if(x<m) update(lc,x,y,k);
    if(m<=y) update(rc,x,y,k);
    pushup(p);
}

int query(int p,int x,int y)
{
    if(x<=tr[p].l&&tr[p].r<=y)
    {
        return tr[p].sum;
    }
    int res=0;
    int m=x+y>>1;
    if(x<m) res+=query(lc,x,y);
    if(m<=y) res+=query(rc,x,y);
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    return 0;
}