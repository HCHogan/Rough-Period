#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

struct node
{
    int s[2];
    int val,cnt,size,p;
    void init(int va,int pa)
    {
        this->val=va;
        this->p=pa;
    }
}tr[N];

int idx,n,root;

void pushup(int u)
{
    tr[u].size=tr[tr[u].s[0]].size+tr[tr[u].s[1]].size+tr[u].cnt;
}

int rotate(int x)
{
    int y=tr[x].p;
    int z=tr[y].p;
    int k=tr[y].s[1]==x;
    tr[y].s[k]=tr[x].s[k^1];
    tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y;
    tr[y].p=x;
    tr[z].s[tr[z].s[1]==y]=x;
    tr[x].p=z;
    pushup(y),pushup(x);
}

void splay(int x,int k)
{
    int y=tr[x].p;
    int z=tr[y].p;
    while(z!=k)
    {
        (tr[z].s[0]==y)^(tr[y].s[0]==x) ? rotate(x):rotate(y);
        rotate(x);
    }
    if(k==0) root=x;            //0节点是根节点上面一个空节点 转到0节点下面意味着0节点就是整棵树的根节点
}

void find(int v)
{
    int x=root;
    while(tr[x].s[v>tr[x].val]&&v!=tr[x].val)
    {
        x=tr[x].s[v>tr[x].val];
    }
    splay(x,0);
}

int get_prev(int v)
{
    find(v);
    int x=root;
    if(tr[x].val<v) return x;           //如果tr[x].val<v 说明没找到v 
    x=tr[x].s[0];                       //但是找出来那个如果比v小那一定是最靠近v的数 所以return x
    while(tr[x].s[1]) x=tr[x].s[1];     //如果tr[x].val>v 那说明也没找到v 但是他是靠v最近的一个比v大的数
    return x;                           //往左找依然是要的那个答案
}

int get_suc(int v)
{
    find(v);
    int x=root;
    if(tr[x].val>v) return x;
    x=tr[x].s[1];
    while(tr[x].s[0]) x=tr[x].s[0];
    return x;
}

void del(int v)
{
    int pre=get_prev(v);
    int suc=get_suc(v);
    splay(pre,0);           //将pre旋转到跟节点下面 再将suc旋转到prev下面可以保证
    splay(suc,pre);
    int tobedel=tr[suc].s[0];
    if(tr[tobedel].cnt>1)
    {
        tr[tobedel].cnt--;
        splay(tobedel,0);
    }
    else
    {
        tr[suc].s[0]=0;
        splay(suc,0);
    }
}

int get_rank(int v)
{
    find(v);
    return tr[tr[root].s[0]].size;
}

int get_val(int rank)       //调用的时候要+1 因为有哨兵节点
{
    int x=root;
    while(1)
    {
        if(tr[x].cnt+tr[tr[x].s[0]].size>rank)
        {
            x=tr[x].s[1];
            rank-=tr[x].cnt+tr[tr[x].s[0]].size;
        }
        else if(tr[tr[x].s[1]].size>=rank)
        {
            x=tr[x].s[0];
        }
        else break;
    }
    splay(x,0);
    return tr[x].val;
}

void insert(int v)
{
    int x=root,p=0;     //x是向下搜的指针 p是x的父亲
    while(x&&tr[x].val!=v)
    {
        p=x;
        x=tr[x].s[v>tr[x].val];
    }
    if(x) tr[x].cnt++;
    else
    {
        x=++idx;
        tr[p].s[v>tr[x].val];
        tr[x].init(v,p);
    }
}

int main()
{
    insert(-INF),insert(INF);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op,x;
        cin>>op>>x;
        if(op==1) insert(x);
        if(op==2) del(x);
        if(op==3) cout<<get_rank(x)<<endl;
        if(op==4) cout<<get_val(x)<<endl;
        if(op==5) cout<<get_prev(x)<<endl;
        if(op==6) cout<<get_suc(x)<<endl;
    }
    return 0;
}