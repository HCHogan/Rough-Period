#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int idx=0,n,m;  //节点编号从0开始
int root=0;     //根结点编号

struct Node
{
    int L,R;
    int key,val;        //key为值 val位随机值
    int cnt,size;       //cnt为这个数出现的次数 size为以当前这个点为根结点 子树的数量
}tr[N];

int new_node(int key)
{
    tr[++idx].key=key;
    tr[idx].val=rand();
    tr[idx].cnt=1;
    tr[idx].size=1;
    return idx;
}

void pushup(int u)
{
    tr[u].size=tr[tr[u].L].size+tr[tr[u].R].size+tr[u].cnt;
}

void zig(int& p)        //zigzag不影响中序遍历的结果!!!旋转是为了保持大堆 让他平衡
{
    int& q=tr[p].L;
    tr[p].L=tr[q].R;
    tr[q].R=p;
    p=q;
    pushup(p),pushup(tr[p].R);      //旋转过就要重新更新p也就是根节点的size
}

void zag(int& p)
{
    int& q=tr[p].R;
    tr[p].R=tr[q].L;
    tr[q].L=p;
    p=q;
    pushup(p),pushup(tr[p].L);
}

void insert(int& p,int key)
{
    if(!p) new_node(key);       //p=0代表是叶子节点 因为没有初始化的tr[p].L或者
    else if(key==tr[p].key) tr[p].cnt++;    //tr[p].R=0;
    else if(key<tr[p].key)
    {
        insert(tr[p].L,key);
        if(tr[tr[p].L].val>tr[p].val) zig(p);       //返回的时候平衡
    }
    else if(key>tr[p].key)
    {   
        insert(tr[p].R,key);
        if(tr[tr[p].R].val<tr[p].val) zag(p);
    }
    pushup(p);      //只要zigzag过都要更新tr[p].size
}

void del(int& p,int key)
{
    if(!p) return;
    if(tr[p].key==key)
    {
        if(tr[p].cnt>1) tr[p].cnt--;
        else if(tr[p].L||tr[p].R)
        {
            if(!tr[p].R||tr[tr[p].L].val>tr[p].val)
            {
                zig(p);     //先转再删
                del(tr[p].R,key);
            }
            else
            {
                zag(p);
                del(tr[p].L,key);
            }
        }
        else p=0;
    }

    if(key<tr[p].key) del(tr[p].L,key);
    else del(tr[p].R,key);

    pushup(p);      //只要zigzag 都要pushup维护tr[p].size
}

int get_rank_by_key(int p,int key)
{
    if(!p) return 0;
    if(key==tr[p].key) return tr[tr[p].L].size+1;
    if(key<tr[p].key) return get_rank_by_key(tr[p].L,key)+1;
    return tr[tr[p].L].size+tr[p].cnt+get_rank_by_key(tr[p].R,key);
}

int get_key_by_rank(int p,int rank)
{
    if(!p) return INF;
    if(tr[tr[p].L].size>=rank) return get_key_by_rank(tr[p].L,rank);
    if(tr[tr[p].L].size+tr[p].cnt>=rank) return tr[p].key;
    return get_key_by_rank(tr[p].R,rank-tr[tr[p].L].size-tr[p].cnt);
}

int get_prev(int p,int key)
{
    if(!p) return -INF;
    if(key<=tr[p].key) return get_prev(tr[p].L,key);
    return max(tr[p].key,get_prev(tr[p].R,key));
}

int get_next(int p,int key)
{
    if(!p) return INF;
    if(key>=tr[p].key) return get_next(tr[p].R,key);
    return min(tr[p].key,get_next(tr[p].L,key));
}

void init_build()       //初始化
{
    new_node(-INF),new_node(INF);
    root=1;
    tr[1].R=2;
    pushup(root);
    if(tr[1].val>tr[2].val) zag(root);
}

int main()
{
    init_build();

    cin>>n;

    while(n--)
    {
        int op,x;
        cin>>op>>x;
        if(op==1) insert(root,x);
        if(op==2) del(root,x);
        if(op==3) get_rank_by_key(root,x);
        if(op==4) get_key_by_rank(root,x);
        if(op==5) get_prev(root,x);
        if(op==6) get_next(root,x);
    }
    return 0;
}