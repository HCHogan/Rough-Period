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
        if(tr[p].)
    }
}