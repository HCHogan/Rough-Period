#include<iostream>
using namespace std;

const int N=10010,INF=0x3f3f3f3f;

struct Node
{
    int L,R;
    int size,cnt;
    int key,val;
}tr[N];

int n,m,root,idx;

int pushup(int p)
{
    tr[p].size=tr[p].cnt+tr[tr[p].L].size+tr[tr[p].R].size;
}

int zig(int& p)
{
    int q=tr[p].L;
    tr[p].L=tr[q].R;
    tr[q].R=p;
    p=q;
}

int zag(int& p)
{
    int q=tr[p].R;
    tr[p].R=tr[q].L;
    tr[q].L=p;
    p=q;
}

int new_node(int key)
{
    tr[++idx].key=key;
    tr[idx].val=rand();
    tr[idx].size=1;
    tr[idx].cnt=1;
}

int insert(int& p,int key)
{
    if(!p) new_node(key);
    else if(key==tr[p].key) tr[p].cnt++;
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

int del(int& p,int key)
{
    if(!p) return 0;
    if(key==tr[p].key)
    {
        if(tr[p].cnt>1) tr[p].cnt--;
        else if(tr[p].L||tr[p].R)
        {
            if(!tr[p].R||tr[tr[p].L].val>tr[p].val)
            {
                zig(p);
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

    pushup(p);
}

void init_build()
{
    new_node(-INF),new_node(INF);
    root=1;
    tr[1].R=2;
    pushup(root);
    if(tr[root].val<tr[2].val) zag(root);
}

int get_rank_by_key(int p,int key)
{
    if(!p) return 0;
    if(tr[p].key==key) return tr[tr[p].L].size;
    else if(tr[p].key<key) return get_rank_by_key(tr[p].L,key);
    else return tr[tr[p].L].size+tr[p].cnt+get_rank_by_key(tr[p].R,key);
}

int get_key_by_rank(int p,int rank)
{
    if(!p) return INF;
    if(tr[tr[p].L].size>=rank) return get_key_by_rank(tr[p].L,rank);
    else if(tr[tr[p].L].size+tr[p].size>=rank) return tr[p].key;
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
    return min(tr[p].key,get_prev(tr[p].L,key));
}

int main()
{
    cin>>n;

    init_build();

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