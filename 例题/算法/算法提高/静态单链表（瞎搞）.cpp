#include<iostream>
using namespace std;
const int N=10010;
class 低级list
{
private:
    int head,idx,nex[N],v[N];
public:
    void push_front(int x)
    {
        v[idx]=x;
        nex[idx]=head;
        head=idx++;
    }
    void erase(int k)
    {
        nex[k]=nex[nex[k]];     //删除k后面那个元素
    }
    void push_back(int x)
    {
        v[idx]=x;
        nex[idx-1]=idx;
        nex[idx++]=-1;
    }
    void insert(int n,int x)
    {
        v[idx]=x;
        nex[idx]=nex[n];
        nex[n]=idx++;
    }
    void traverse()
    {
        for(int i=head;~i;i=nex[i]) cout<<v[i]<<" ";
    }
    void init()
    {
        head=-1;
        idx=0;
    }
};
低级list lst;
int main()
{
    lst.init();
    lst.push_back(1);
    lst.push_back(2);
    lst.push_front(0);
    lst.traverse();
    return 0;
}