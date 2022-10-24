#include<iostream>
using namespace std;
int book[10001],a[10001],n;
int dfs(int u)
{
    if(u>n)
    {
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        puts("");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i]==1) continue;
        a[u]=i;
        book[i]=1;
        dfs(u+1);
        book[i]=0;
    }
}
int main()
{
    cin>>n;
    dfs(1);
    return 0;
}