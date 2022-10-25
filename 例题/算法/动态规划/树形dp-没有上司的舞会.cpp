#include<iostream>
#include<vector>
using namespace std;
const int N=10010;

vector<int> h[N];

int f[N][2],n;      //f[i][0]表示不选i节点 该子树的快乐值 f[i][1]表示选...
int w[N];

void dfs(int u)
{
    f[u][1]=w[u];
    for(auto s:h[u])
    {
        dfs(s);
        f[u][1]+=f[s][0];
        f[u][0]+=max(f[s][0],f[s][1]);
        return;
    }
}

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }

    for(int i=1;i<=n;i++)
    {
        int sum_son;
        cin>>sum_son;
        for(int j=1;j<=sum_son;j++)
        {
            int x;
            cin>>x;
            h[i].push_back(x);
        }
    }

    int root=1;
    dfs(root);

    cout<<max(f[1][0],f[1][1]);

    return 0;
}