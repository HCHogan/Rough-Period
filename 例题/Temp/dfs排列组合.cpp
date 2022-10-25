#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
int n,a[N];
bool book[N];
void dfs(int u)
{
    if(u>n)
    {
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        puts("");
        return;
    }
    for(int j=1;j<=n;j++)
    {
        if(!book[j])
        {
            a[u]=j;
            book[j]=1;
            dfs(u+1);
            book[j]=0;
        }
    }
}
int main()
{
    cin>>n;
    memset(book,0,sizeof book);
    dfs(1);
    return 0;
}