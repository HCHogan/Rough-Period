#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef struct Bnode          //1，定义了一个名为struct Bnode的结构体 里面包含一些东西
{                             //2，给struct Bnode取了个新名字叫做Bnode
    char data;
    struct Bnode *lchild;
    struct Bnode *rchild;
}Bnode, *Btree;               //也可以 Bnode *Btree;
void preorder(Btree T) //先序遍历  
{
    if(T)
    {
        cout<<T->data<<" ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
void inorder(Btree T) //中序遍历
{
    if(T)
    {
        inorder(T->lchild);
        cout<<T->data<<" ";
        inorder(T->rchild);
    }
}
void posorder(Btree T) //后序遍历
{
    if(T)
    {
        posorder(T->lchild);
        posorder(T->rchild);

    }
}
bool Leveltraverse(Btree T)  //层序遍历
{
    Btree p;
    if(!T) return false;
    queue<Btree>Q;
    Q.push(T);
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        cout<<p->data<<" ";
        if(p->lchild) Q.push(p->lchild);
        if(p->rchild) Q.push(p->rchild);
    }
    return true;
}
string s1,s2;
void pre_in_calcPost(int ileft1,int iright1,int ileft2,int iright2)
{
    int mid=s2.find(s1[ileft1]);
    if(mid>ileft2) pre_in_calcPost(ileft1+1,ileft1+mid-ileft2,ileft2,mid-1);
    if(mid<ileft2) pre_in_calcPost(ileft1+mid-ileft2+1,iright1,mid+1,iright2);
    cout<<s1[ileft1];
}
int main()
{
    return 0;
}
