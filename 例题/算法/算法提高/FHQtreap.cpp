#include<iostream>
using namespace std;
const int N=10010;

//fhq-treap 除了要满足关于key的BST性质之外，还需满足关于val的小根堆性质
//对于任意fhq-treap中的节点 i ，
//  其左子树上的所有节点的key小于等于 i 节点的key值，
//  i 节点所有右子树上所有节点的key 大于等于 i 节点的key值
//对于任意节点 i ，其左、右儿子的val值大于等于 i 的val值(满足小根堆的性质)。
struct node
{
    int l,r,val,key,size;
}tr[N];

int n,root,idx;

int newnode(int v)
{
    tr[++idx].val=v;
    tr[idx].key=rand();
    tr[idx].size=1;
    return idx;
}

void pushup(int p)
{
    tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+1;
}

void split(int p,int v,int& x,int &y)
{
    if(!p)
    {
        x=y=0;
        return;
    }
    if(v<=tr[p].val)
    {
        y=p;
        split(tr[p].l,v,x,tr[p].l);
    }
    else
    {
        x=p;
        split(tr[p].r,v,tr[p].r,y);
    }
    pushup(p);
}

int merge(int x,int y)      //x的节点必须全部小于y
{                           //split保证了这件事情
    if(!x||!y) return x+y;
    if(tr[x].val<tr[y].val)
    {
        tr[y].l=merge(x,tr[y].l);
        pushup(y);
        return y;
    }
    else
    {
        tr[x].r=merge(tr[x].r,y);
        pushup(x);
        return x;
    }
}       //merge函数返回的是合并完的树的跟节点

void insert(int v)
{
    int x,y,z;      //x,y接受把p分裂以后的左右字树的节点
    split(root,v,x,y);
    z=newnode(v);
    root=merge(merge(x,z),y);
}

void del(int v)
{
    int x,y,z;      //x,y,z分别指向小于v的那棵树 v本身那棵树 大于v的那棵树
    split(root,v,x,z);
    split(x,v-1,x,y);
    y=merge(tr[y].l,tr[y].r);       //把y指向合并y下面两个字树后的根节点 虽然有一个字树是空集
    merge(merge(x,y),z);            //再缝合 相当于删除y 6
}

//由于是二叉查找树 因此其他函数和treap一样

int get_k(int p,int k)      //返回第k个节点的编号
{
    if(k<=tr[tr[p].l].size)
        return get_k(tr[p].l,k);
    if(k==tr[tr[p].l].size+1)
        return p;
    return get_k(tr[p].r,k-tr[tr[p].l].size-1);     //与splay等相同
}

int get_prev(int v)
{
    int x,y;
    split(root,v-1,x,y);
    int p=get_k(x,tr[x].size);
    root=merge(x,y);
    return tr[p].val;
}

int get_suc(int v)
{
    int x,y;
    split(root,v+1,x,y);
    int p=get_k(y,1);
    root=merge(x,y);
    return tr[p].val;
}

int main()
{
    cin>>n;
    return 0;
}