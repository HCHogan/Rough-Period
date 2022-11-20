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

int n,m,idx,w[N];

void pushup(int p)
{
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void pushdown(int p)
{
    if(!tr[p].add) return;
    tr[lc].sum+=tr[p].add*(tr[lc].r-tr[lc].l+1);
    tr[rc].sum+=tr[p].add*(tr[rc].r-tr[rc].l+1);
    tr[lc].add+=tr[p].add;
    tr[rc].add+=tr[p].add;
    tr[p].add=0;
}

void update(int p,int x,int y,int k)
{
    if(x<=tr[p].l&&tr[p].r<=y)
    {
        tr[p].sum+=k*(tr[p].r-tr[p].l+1);
        tr[p].add+=k;
        return;
    }
    int m=x+y>>1;
    pushdown(p);
    if(x<m) update(lc,x,y,k);       //直接传x和y 不用m来划分
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
    int m=tr[p].l+tr[p].r>>1;
    if(x<m) res+=query(lc,x,y);
    if(m<=y) res+=query(rc,x,y);
    return res;
}

void build(int p,int x,int y)
{
    tr[p].l=x;
    tr[p].r=y;
    tr[p].sum=w[x];
    if(x==y) return;
    int m=m+y>>1;
    build(lc,x,m);
    build(rc,m+1,y);
    pushup(p);
}

int main()
{
    cin>>n>>m;
    return 0;
}