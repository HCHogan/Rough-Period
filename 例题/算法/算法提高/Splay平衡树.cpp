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
    if(k==0) root=x;
}

void find(int x)
{

}