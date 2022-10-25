#include<iostream>
using namespace std;
const int N=10010;
//右子链永远是单调栈里的内容
//一个进来的元素干掉一些节点后使右子链还是单调栈 然后把干掉的那些元素挂在左孩子处
int stk[N],top=0;
int n;
int w[N],L[N],R[N];
int root=-1;
bool have_fa[N];
int q[N],tt=0,hh=0;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k=top;
        while(k&&w[stk[k]]>w[i]) k--;
        if(k) R[stk[k]]=i;
        if(k<top) L[i]=stk[k+1],have_fa[stk[k]]=1;
        stk[++k]=i;
        top=k;
    }

    for(int i=1;i<=n;i++)
    {
        if(!have_fa[i])
        {
            root=i;
            break;
        }
    }

    q[tt++]=root;
    while(hh<tt)
    {
        int t=q[hh++];
        cout<<t<<" ";
        if(L[t]) q[tt++]=L[t];
        if(R[t]) q[tt++]=R[t];
    }
    return 0;
}