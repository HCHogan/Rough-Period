#include<iostream>
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N=10010;

int n,root,idx;

struct node
{
    int s[2];
    int tag,cnt,size,p;
    int val;
}tr[4*N];

void rotate(int x)
{
    
}

void splay(int x,int k)
{
    int y=tr[x].p,z=tr[y].p;
    while(tr[x].p!=k)
    {
        if(z!=k)
        {
            tr[z].s[1]==y&&tr[y].s[1]==x
                ? rotate(x):rotate(y);
        }
    }
}

void pushdown(int x)
{
    if(tr[x].tag)
    {
        swap(tr[x].s[0],tr[x].s[1]);
        tr[tr[x].s[0]].tag^=1;
        tr[tr[x].s[1]].tag^=1;
        tr[x].tag=0;
    }
}

int get_k(int k)        //获取第k个节点编号
{
    int x=root;
    while(1)
    {
        pushdown(x);
        int y=tr[x].s[0];
        if(tr[y].size<k)
        {
            x=y;
        }
        else if(tr[x].cnt+tr[y].size<k)
        {
            k-=tr[x].cnt+tr[y].size;
            x=tr[x].s[1];
        }
        else return x;
    }
}

int main()
{
    cin>>n;
    //insert(-INF),insert(INF);
    while(n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int l=get_k(x),r=get_k(y+2);    //因为有哨兵 所以+2
        splay(l,0);     //将l,r夹在中间
        splay(r,l);
        tr[tr[r].s[0]].tag^=1;  //这个既是要反转的一串
    }
}