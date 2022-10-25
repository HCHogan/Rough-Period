#include<iostream>
#include<vector>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int ans,n,m;
vector<int> h[N],vis[N];

int dfs(int u)
{

}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        h[a].push_back(b);
        h[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        
    }
}