#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

struct node
{
    int L,R;
    int key,val;
    int cnt,size;
}tr[N];

int n,idx,root;

int newnode(int key)
{
    tr[++idx].key=key;
    tr[idx].val=rand();
    tr[idx].cnt=tr[idx].size=1;
}

int pushup(int u)
{
    tr[u].size=tr[u].cnt+tr[tr[u].L].cnt+tr[tr[u].R].cnt;
}

int zag(int& p)
{
    int q=tr[p].L;
    tr[p].L=tr[q].R;
    tr[q].R=p;
    p=q;
    pushup(tr[p].R),pushup(p);
}

int zig(int& p)
{
    int q=tr[p].R;
    tr[p].R=tr[q].L;
    tr[q].L=p;
    p=q;
    pushup(tr[p].L),pushup(p);
}

int init_build()
{
    newnode(-INF);
    newnode(INF);
    root=1;
    tr[root].R=2;
    pushup(root);
    if(tr[1].val<tr[2].val) zag(root);      //左旋
}

void insert(int& p,int key )
{
    if(!p) p=newnode(key);
    if(key==tr[p].key) tr[p].cnt++;
    else if(key<tr[p].key)
    {
        insert(tr[p].L,key);
        if(tr[tr[p].L].val>tr[p].val) zig(p);
    }
    else
    {
        insert(tr[p].R,key);
        if(tr[tr[p].R].val>tr[p].val) zag(p);
    }
    pushup(p);
}

void del(int& p,int key)
{
    if(!p) return;
    if(tr[p].key==key)
    {
        if(tr[p].cnt>1) tr[p].cnt--;
        else if(!tr[p].R||tr[tr[p].L].val>tr[tr[p].R].val)      //因为要删除key这个节点 所以可以让他特例 val不一定满足大根堆 反正最后要删掉
        {       //一路从根旋转到叶节点 最后删除
            zig(p);     //zigzag不改变二叉查找数 只是把key这个节点旋转到叶子节点
            del(tr[p].R,key);
        }
        else
        {
            zag(p);
            del(tr[p].L,key);
        }
    }
    else p=0;       //这个指针指0 断边

    if(key<tr[p].key) del(tr[p].L,key);
    else del(tr[p].R,key);

    pushup(p);
}

int get_rank_by_key(int p,int key)
{
    if(!p) return 0;
    if(key==tr[p].key) return tr[tr[p].L].size+1;
    if(key<tr[p].key) return get_rank_by_key(tr[p].L,key);
    if(key>tr[p].key) return tr[tr[p].L].size+tr[p].cnt+get_rank_by_key(tr[p].R,key);
}

int get_key_by_rank(int p,int rank)
{
    if(!p) return INF;
    if(rank<=tr[tr[p].L].cnt) return get_key_by_rank(tr[p].L,rank);
    if(rank>tr[tr[p].L].cnt+tr[p].size)
        return get_key_by_rank(tr[p].R,rank-tr[tr[p].L].size-tr[p].cnt);
    return tr[p].key;
}

int get_prev(int p,int key)
{
    if(!p) return -INF;
    if(key<=tr[p].key) return get_prev(tr[p].L,key);
    if(key>tr[p].key) return max(tr[p].key,get_prev(tr[p].R,key));
}       //有可能右孩子没有左孩子

int get_next(int p,int key)
{
    if(!p) return INF;
    if(key>=tr[p].key) return get_next(tr[p].R,key);
    if(key<tr[p].key) return min(tr[p].key,get_prev(tr[p].L,key));
}       //有可能左孩子没有右孩子

int main()
{
    cin>>n;
    while(n--)
    {
        int op,x;
        cin>>op>>x;
        if(op==1) insert(root,x);
        else if(op==2) del(root,x);
        else if(op==3) cout<<get_rank_by_key(root,x)-1<<endl;
        else if(op==4) cout<<get_key_by_rank(root,x+1)<<endl;       //引入正无穷和负无穷后 会对排名造成影响
        else if(op==5) cout<<get_prev(root,x)<<endl;
        else cout<<get_next(root,x)<<endl;
    }
    return 0;
}