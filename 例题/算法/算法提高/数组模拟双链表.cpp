#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
int l[N],r[N],v[N];     //head，xxx，tail
int idx=0,m;      //标记
void init()
{
    r[0]=1;
    l[1]=0;
    idx=2;
}
void insert(int k,int x)        //插在k的左边一位
{
    v[idx]=x;
    r[idx]=r[k];
    l[idx]=k;
    l[r[k]]=idx;
    r[k]=idx++;
}
void del(int k)     //删除k这一位
{
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}
void traverse()
{
    for(int i=0;i!=1;i=r[i]) cout<<v[i]<<" ";       //头节点的地址是1（用数组模拟，用指针好机）
}
int main()
{
    cin>>m;
    string op;
    cin>>op;
    if(op=="R")
    {
        int x;
        cin>>x;
        insert(l[1],x);     //头插
    }
    else if(op=="D")
    {
        int k;
        cin>>k;
        del(k+1);
    }
    else if(op=="IL")
    {
        int k,x;
        cin>>k>>x;
        insert(k,x);
    }
    else
    {
        int k,x;
        insert(k+1,x);
    }
    return 0;
}