#include<iostream>
#define notroot(x) tr[tr[x].p].s[0]==x||tr[tr[x].p].s[1]==x
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

struct node
{
    int s[2];
    int p,v,sum;
    int tag;
}tr[N];

int n,root,idx;

void pushup(int x)      //异或和相当于二进制不进位的加法 这道题要求维护区间异或和
{
    tr[x].sum=tr[tr[x].s[1]].sum^tr[tr[x].s[0]].sum^tr[x].v;
}

void pushdown(int x)
{
    if(tr[x].tag)
    {
        swap(tr[x].s[0],tr[x].s[1]);
        tr[tr[x].s[1]].tag^=1;
        tr[tr[x].s[0]].tag^=1;
        tr[x].tag=0;
    }
}

void pushall(int x)
{
    if(notroot(x)) pushall(tr[x].p);    //先一直找到根节点 再一次向下down
    pushdown(x);
}

void rotate(int x)
{
    int y=tr[x].p;
    int z=tr[y].p;
    if(notroot(x))
    {
        tr[z].s[y==tr[x].s[1]]=x;       //当他不是下面那个树的根节点的时候
        //连接从父亲到儿子
    }
    tr[x].p=z;
    int k=tr[z].s[1]==y;
    tr[y].s[k]=tr[x].s[k^1];
    tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y;
    tr[y].p=x;
    pushup(y);
    pushup(x);
}

void splay(int x)
{
    pushall(x);             //使懒标记生效 因为接下来伸展操作会打乱顺序
    while(notroot(x))       //将x翻转到根节点，所以当他不是更节点的时候做这件事情
    {
        int y=tr[x].p;
        int z=tr[y].p;
        if(notroot(z))
        {
            (tr[z].s[1]==y)^(tr[y].s[1]==x)
            ? rotate(x):rotate(y);
        }
        rotate(x);
    }
}

void access(int x)
{
    for(int y=0;x;)
    {
        splay(x);
        tr[x].s[2]=y;       //深度深的点一定在下面
        pushup(x);
        y=x,x=tr[x].p; 
    }
}

int makeroot(int x)
{
    access(x);
    rotate(x);
    tr[x].tag^=1;       //翻转
}

void split(int x,int y)     //将x和y单独分出来
{
    makeroot(x);
    access(y);
    splay(y);
}

void output(int x,int y)
{
    split(x,y);
    printf("%d",tr[y].sum);
}

int findroot(int x)
{
    access(x);
    splay(x);
    while(tr[x].s[0])
    {
        pushdown(x);        //under any circumstances
        x=tr[x].s[0];       //在往下找的时候都要使懒标记下传
    }
    splay(x);       //防止毒瘤数据反复查询一个地方TE
    return x;
}