#include<iostream>
#include<iomanip>
using namespace std;
int path[21]={0};
int n,m;
void dfs(int u)
{
    if(u>m)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<setw(3)<<path[i];
        }
        cout<<endl;
        return;
    }
    for(int i=path[u-1]+1;i<=n;i++)
    {
        path[u]=i;
        dfs(u+1);
    }
}

int main()
{
    cin>>n>>m;
    dfs(1);
    return 0;
}