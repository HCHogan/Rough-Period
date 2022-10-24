#include<iostream>
using namespace std;
const int N=30;
int n,m;
int path[N];

void dfs(int u)
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
    for(int i=path[u-1]+1;i<=n;i++)//至少是前一个的+1项，与传入怕热pre参数一样
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
