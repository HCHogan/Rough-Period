#include<iostream>
using namespace std;
int n,path[10001],ans=0;
bool hash0[10001];
void dfs(int u,int sum)
{
    if(u>n)
    {
        hash0[sum]=1;
        return;
    }
    dfs(u+1,sum);
    dfs(u+1,sum+path[u]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>path[i];
    dfs(1,0);
    for(int i=1;i<=10000;i++) if(hash0[i]) ans++;
    cout<<ans;
    return 0;
}