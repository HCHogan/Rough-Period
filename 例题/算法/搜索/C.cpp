#include<iostream>
#include<cstring>
using namespace std;
bool path[10001];
int n,m;
void dfs(int u,int st)
{
    if(u>m)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=st;i<=n;i++)
    {
        path[u]=i;
        dfs(u+1,i+1);
    }
}
int main()
{
    cin>>n>>m;
    memset(path,0,sizeof path);
    dfs(1,1);
    return 0;
}
