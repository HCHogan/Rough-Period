#include<iostream>
#include<cmath>
//这里默认有个满二叉树，因此只要存每个节点的bool值就行了
using namespace std;
bool a[10001];
int D,n,ans;
void drop(int k);//k是节点编号
int main()
{
    cin>>D>>n;
    for(int i=1;i<=n;i++)//模拟掉n次小球
    {
        drop(1);
    }
    cout<<ans;
}

void drop(int k)
{
    if(k>=pow(2.0,D-1)&&k<pow(2.0,D))
    {
        ans=k;
        return;
    }
    if(a[k])
    {
        a[k]=!a[k];
        drop(2*k+1);
    }
    else
    {
        a[k]=!a[k];
        drop(2*k);
    }
}