#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
struct Tr
{
    int L;
    int R;
    int maxdat;
}tr[N];
int n,q;
void build(int u,int L,int R)
{
    tr[u]={L,R};
    if(L==R) return;
    int mid=L+R>>1;
    build(u<<1,L,mid);
    build(u<<1+1,mid+1,R);
    return;
}
void pushup(int u)                  //修改父节点
{
    tr[u].maxdat=max(tr[u<<1].maxdat,tr[u<<1|1].maxdat);
}
void update(int u,int x,int dat)        //单点更新
{
    if(tr[u].L==tr[u].R)
    {
        tr[u].maxdat=dat;       //加就用+=dat
        return;
    }
    int mid=tr[u].L+tr[u].R<<1;
    if(mid<=x) update(u<<1,x,dat);
    else update(u<<1+1,x,dat);
    pushup(u);
    return;
}
int QueryMax(int u,int L,int R)     //查询[L,R]区间最大值为多少
{
    if(tr[u].L>=L&&tr[u].R<=R) return tr[u].maxdat;
    int mid=tr[u].L+tr[u].R>>1;
    int res=0;
    if(L<=mid) res=QueryMax(u<<1,L,R);
    if(R>mid) res=max(res,QueryMax(u<<1|1,L,R));
    return res;
}
int main()
{
    while(cin>>n,cin>>q)
    {
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            update(1,i,x);
        }
        for(int i=1;i<=q;i++)
        {
            char c;
            cin>>c;
            if(c=='Q')
            {
                int L,R;
                cin>>L>>R;
                printf("%d\n",QueryMax(1,L,R));
            }
            if(c=='U')
            {
                int i,dat;
                cin>>i>>dat;
                update(1,i,dat);
            }
        }
    }
    return 0;
}