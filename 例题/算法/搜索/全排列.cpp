#include<iostream>
using namespace std;
int n=9,a[10001],cnt=0;
bool book[10001];   //标记这张牌是否被用过
void dfs(int u)
{
    if(u>n)
    {
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]==a[7]*100+a[8]*10+a[9]) cnt++;
        return;
    }
    for(int i=1;i<=n;i++)         //i指编号为i的牌
    {
        if(book[i]) continue;     //如果这张牌被用过 准备用下一张牌
        a[u]=i;                   //第u个盒子放入i
        book[i]=1;                //第i张牌被标记用过
        dfs(u+1);                 //搜下面一堆盒子
        book[i]=false;            //搜完下面一堆盒子 把当前这个盒子里的那张牌取出 继续试手里的下一张牌
    }
}
int main()
{
    dfs(1);
    cout<<cnt;
    return 0;
}