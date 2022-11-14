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

void pushup(int u)
{
    tr[u].size=tr[u].cnt+tr[tr[u].L].size+tr[tr[u].R].size;
}

void zig(int& p)
{
    int q=tr[p].L;
    tr[p].L=tr[q].R;
    tr[q].R=p;
    p=q;
}

void zag(int& p)
{
    int q=tr[p].R;
    tr[p].R=tr[q].L;
    tr[q].L=p;
    p=q;
}

int build()
{
    newnode(-INF);
    newnode(INF);
    root=1;
    tr[1].R=2;
    if(tr[1].val<tr[2].val) zag(root);
    pushup(root);
}

int insert(int& p,int key)
{
    if(!p) newnode(key);
    if(tr[p].key==key) tr[p].cnt++;
    else if(key<tr[p].key)
    {
        insert(tr[p].L,key);
        if(tr[p].val<tr[tr[p].L].val) zig(p);
    }
    else
    {
        insert(tr[p].R,key);
        if(tr[p].val<tr[tr[p].R].val) zag(p);
    }
    pushup(p);
}

void del(int p,int key)
{
    if(!p) return;
    if(key==tr[p].key)
    {
        if(tr[p].L||tr[p].R)
        {
            if(!tr[p].R&&tr[tr[p].L].val>tr[tr[p].R].val)
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

int get_key_by_rank(int p,int rank)
{
    if(!p) return INF;
    if(rank<=tr[tr[p].L].size) return get_key_by_rank(tr[p].L,rank);
    if(rank>tr[tr[p].L].size+tr[p].cnt)
        return get_key_by_rank(tr[p].R,rank-tr[tr[p].L].size-tr[p].cnt);
    return tr[p].key;
}

int get_rank_by_key(int p,int key)
{
    if(!p) return INF;
    if(key==tr[p].key) return tr[tr[p].L].size+1;
    else if(key<tr[p].key) return get_rank_by_key(tr[p].L,key);
    else return get_rank_by_key(tr[p].R,key)+tr[tr[p].L].size+tr[p].cnt;
}

int get_prev(int p,int key)
{
    if(!p) return -INF;
    if(key<=tr[p].key) return get_prev(tr[p].L,key);
    return max(get_prev(tr[p].L,key),tr[p].key);
}

int get_ne(int p,int key)
{
    if(!p) return INF;
    if(key>=tr[p].key) return get_ne(tr[p].R,key);
    return min(tr[p].key,get_ne(tr[p].L,key));
}