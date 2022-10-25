#include<iostream>
using namespace std;
const int N=10001;
int n,m;     //一共n个 背包总容量为m  
long long f[N];   //f[i]表示输入这个数以后当背包空间为i时一共有多少方法
int main()      //放入这个数以后就是 没放入这个数之前空间为i时候的方法数
{               //加上放入这个数之后空间为i-x的方法之和
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=m;j>=x;j--)
            f[j]+=f[j-x];
    }
    cout<<f[m];
}