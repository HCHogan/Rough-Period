#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int n,T;
struct Tr
{
    int L;
    int R;
    int maxdat;
}tr[N*4];
void build(int u,int L,int R)
{
    tr[u]={L,R};
    if(L==R) return;
    int mid=L+R>>1;
    build(u<<1,L,mid),build(u<<1+1,mid+1,R);
    return;
}
void pushup(int u)
{
    tr[u].maxdat=max(tr[u<<1].maxdat,tr[u<<1|1].maxdat);
}
void update(int u,int i,int dat)
{
    if(tr[u].L==tr[u].R)
    {
        tr[u].maxdat+=dat;
        return;
    }
    int mid=tr[u].L+tr[u].R<<1;
    if(i<=mid) update(u<<1,i,dat);
    else update(u<<1|1,i,dat);
    pushup(u);
}
int QuerySum(int u,int L,int R)
{
    if(tr[u].L>=L&&tr[u].R<=R) return tr[u].maxdat;
    int mid=L+R<<1;
    int res=0;
    if(L<=mid) res=QuerySum(u<<1,L,mid);
    if(R>mid) res+=QuerySum(u<<1|1,mid+1,R);
    return res;
}
int main()
{
    cin>>T;
    int idx=0;
    while(T--)
    {
        cin>>n;
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            update(1,i,x);
        }
        string op;
        while(cin>>op,op!="End")
        {
            int i,x;
            cin>>i>>x;
            if(op=="Add") update(1,i,x);
            if(op=="Sub") update(1,i,-x);
            if(op=="Sum") printf("%d\n",QuerySum(1,i,x));
        }
    }
    return 0;
}