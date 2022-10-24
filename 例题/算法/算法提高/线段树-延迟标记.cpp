#include<iostream>
using namespace std;
const int N=10010;
typedef long long LL;
int n,m;
int a[N];
struct Tr
{
    int L;
    int R;
    int add;
    int sum;
}tr[N*4];
void pushup(int u)
{
    tr[u].sum=(LL)tr[u<<1].sum+(LL)tr[u<<1|1].sum;
}
void pushdown(int u)
{
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if(root.add)
    {
        left.add=root.add,left.sum+=(LL)(left.R-left.L)*root.add;
        right.add=root.add,right.sum=(LL)(right.R-right.L)*root.add;
        root.add=0;
    }
}
void build(int u,int L,int R)
{
    if(L==R)
    {
        tr[u]={L,R,a[L],0};
        return;
    }
    tr[u]={L,R};
    int mid=tr[u].L+tr[u].R>>1;
    if(L<=mid) build(u<<1,L,mid);
    if(R>mid) build(u<<1|1,mid+1,R);
    pushup(u);
}
LL query(int u,int L,int R)
{
    if(L<=tr[u].L&&tr[u].R>=R) return (LL)tr[u].sum;
    pushdown(u);
    LL res=0;
    int mid=tr[u].L+tr[u].R<<1;
    if(L<=mid) res+=query(u<<1,L,R);
    if(R>mid) res+=query(u<<1|1,L,R);
    return res;
}
void update(int u,int L,int R,int d)
{
    if(L>=tr[u].L&&tr[u].R<=R)
    {
        tr[u].sum+=(LL)d*(tr[u].R-tr[u].L+1);
        tr[u].add+=d;
        return;
    }
    pushdown(u);
    int mid=tr[u].L+tr[u].R>>1;
    if(L<=mid) update(u<<1,L,R,d);
    if(R>mid) update(u<<1|1,L,R,d);
    return;
}