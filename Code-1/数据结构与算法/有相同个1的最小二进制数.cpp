#include<iostream>
using namespace std;
int lowbit(int x)
{
    return x& -x;//去最低位的一
}//负数就是正数的每一位都取反以后再加1

int calc(int x)
{
    int cnt=0;
    while(x)
    {
        x-=lowbit(x);
        cnt++;
    }
    return cnt;
}

int find(int x)
{
    int y=x+1;
    while(calc(y++)!=calc(x));
    return y-1;
}

int main()
{
    int n;
    while(cin>>n,n)
    {
        int ans=find(n);
        cout<<ans<<endl;
    }
}