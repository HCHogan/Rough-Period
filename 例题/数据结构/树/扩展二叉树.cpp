#include<iostream>
using namespace std;

struct BNode
{
    char data;
    int lchild,rchild;
}node[101];  //用数组模拟二叉树

int root=0,cnt=0;
int buildTree(int T)
{
    char ch;
    cin>>ch;
    if(ch=='.') return 0;
    else
    {
        T=++cnt;
        node[T].data=ch;                  //按照前序遍历输入二叉树
        node[T].lchild=buildTree(T);
        node[T].rchild=buildTree(T);
        return T;
    }
}
int preOrder(int T)
{
    if(T)
    {
        cout<<T;
        preOrder(node[T].lchild);
        preOrder(node[T].rchild);
    }
}
int inOrder(int T)
{
    if(T)
    {
        inOrder(node[T].lchild);
        cout<<T;
        inOrder(node[T].rchild);
    }
}
int postOrder(int T)
{
    if(T)
    {
        postOrder(node[T].lchild);
        postOrder(node[T].rchild);
        cout<<T;
    }
}
int main()
{
    root=buildTree(0);
    inOrder(root);
    cout<<endl;
    postOrder(root);
    return 0;
}