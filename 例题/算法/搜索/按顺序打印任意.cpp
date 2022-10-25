#include<iostream>
#include<cstring>
using namespace std;
int n;
bool book[10001];
int dfs(int u)
{
    if(u>n)
    {
        for(int i=1;i<n;i++) if(book[i]) cout<<i<<" ";
        cout<<endl;
        return 0;
    }
    book[u]=1;
    dfs(u+1);
    book[u]=0;
    dfs(u+1);
}
int main()
{
    cin>>n;
    memset(book,0,sizeof book);
    dfs(1);
    return 0;
}