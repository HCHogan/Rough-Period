#include<iostream>
using namespace std;
int work(int m,int n)
{
    //if(n==1) return 1;
    if(n==1||m==0) return 1;
    if(m<n) return work(m,m);//这一步至关重要！没有这一步直接寄，妈蛋！
    //if(m==1) return n;
    return work(m,n-1)+work(m-n,n);//这一步限定n只会到1。
    //当work(m,m)时，第二种情况直接变成work(0,m)从而弹出。
    //而如果不加那一步，m可能会有负数！
}

int main()
{
    int a,m,n;
    cin>>a;
    while(a--)
    {
        cin>>m>>n;
        int ans=work(m,n);
        cout<<ans;
    }
}