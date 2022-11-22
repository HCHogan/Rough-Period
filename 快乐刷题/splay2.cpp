#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

struct node
{
    int s[2];
    int val,size,cnt,pa;
    void init(int p,int v)
    {
        this->pa=p;
        this->val=v;
        cnt=size=1;
    }
}tr[N];

int idx,n,m,root;

void pushup(int p)
{
    tr[p].size=tr[p].cnt+tr[tr[p].s[0]].size+tr[tr[p].s[1]].size;
}

void rotate(int x)
{
    int y=tr[x].pa;
    int z=tr[y].pa;
    int k=tr[y].s[1]==x;
    tr[y].s[k]=tr[x].s[k^1];
    tr[tr[x].s[k^1]].pa=y;
    tr[x].s[k^1]=y;
    tr[y].pa=x;
    tr[z].s[tr[z].s[1]==y]=x;
    tr[x].pa=z;
    pushup(y);
    pushup(x);
}

void splay(int x,int k)
{
    while(tr[x].pa!=k)
    {
        int y=tr[x].pa;
        int z=tr[y].pa;
        if(z!=k)
        {       //折转低 直转中
            (tr[z].s[1]==y)^(tr[y].s[1]==x)     //如果直线 返回值为0 运行rotate(y) 
                ? rotate(x):rotate(y);          //如果折线 返回1 运行rotate(x)
        }
        rotate(x);
    }
    if(k==0) root=x;
}

void find(int v)        //利用二叉查找树找到v对应节点的序号 然后旋转到更节点
{
    int x=root;
    while(v!=tr[x].val&&tr[x].s[v>tr[x].val])
    {
        x=tr[x].s[v>tr[x].val];
    }
    splay(x,0);
}

int get_ne(int v)
{
    find(v);
    int x=root;
    if(v>tr[x].val) return x;
    x=tr[x].s[1];
    while(tr[x].s[0]) x=tr[x].s[0];
    return x;
}

int get_pre(int v)
{
    find(v);
    int x=root;
    if(v<tr[x].val) return x;
    x=tr[x].s[0];
    while(tr[x].s[1]) x=tr[x].s[1];
    return x;
}

void del(int v)
{
    int pre=get_pre(v);
    int ne=get_ne(v);
    splay(pre,0);
    splay(ne,pre);
    int del=tr[ne].s[0];
    if(tr[del].cnt>1)
    {
        tr[del].cnt--;
        splay(del,0);
    }
    else
    {
        tr[ne].s[0]=0;
        splay(ne,0);
    }
}

int get_rank(int v)
{
    find(v);
    return tr[tr[root].s[0]].size;
}

int get_val(int x,int k)
{
    int x=root;
    while(1)
    {
        if(tr[tr[x].s[0]].size+tr[x].cnt<k)
        {
            x=tr[x].s[1];
            k-=tr[tr[x].s[0]].size+tr[x].cnt;
        }
        else if(k<=tr[tr[x].s[0]].size)
        {
            x=tr[x].s[0];
        }
        else break;
    }
    splay(x,0);
    return tr[x].val;
}

void insert(int p,int v)
{
    int p=0,x=root;
    while(x&&tr[x].val!=v)
    {
        p=x;
        x=tr[x].s[v>tr[x].val];
    }
    if(x) tr[x].cnt++;
    else
    {
        x=++idx;
        tr[x].init(p,v);
        tr[p].s[v>tr[p].val]=x;
    }
    splay(x,0);
}