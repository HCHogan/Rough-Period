#include<iostream>
using namespace std;
//核心思想：一个包含此节点所有信息的Node,和一个节点编号,两者相同
//因为此时的节点为Node[T]，编号为T，返回上一层节点并给自己赋值T
int root=1,cnt=0;
struct Node{
    char data;
    int lchild,rchild;//表示左右节点的编号
}node[101];
int createNode(int T);//T为当前节点 
void inOrder(int T);
void postOrder(int T);

int main()
{
    root=createNode(0);//root=cerateNode(T);
    //cout<<root<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    //cout<<cnt;
}

int createNode(int T)
{
    char ch;
    cin>>ch;
    if(ch=='.') {return 0;}
    else {
        T=++cnt;
        node[T].data=ch;
        node[T].lchild=createNode(T);
        node[T].rchild=createNode(T);
    }
    return T;
}
//一路往下先创建左支并创建带有编号的节点Node[T]，遇到.以后返回并出示化0，即为.的那个节点编号为零，节点不存在
//返回上一存在的节点并创建右子节点，然后为.继续返回，此时没有调用，再返回上一层函数的调用为T
//然后上一次把T赋值给左子节点
void inOrder(int T)
{
    if(T)//是否存在该节点。如有数值即被被初始化过，存在
    {
        inOrder(node[T].lchild);
        cout<<node[T].data;
        inOrder(node[T].rchild);
    }
}
void postOrder(int T)
{
    if(T)
    {
        postOrder(node[T].lchild);
        postOrder(node[T].rchild);
        cout<<node[T].data;
    }
}
//ABD..EF..G..C..