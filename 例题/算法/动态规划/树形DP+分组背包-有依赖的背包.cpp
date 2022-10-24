#include<iostream>
#include<vector>
using namespace std;
const int N=10010;

vector<int> h[N];
int n,w[N],v[N],m,x,root;
int f[N][N];        //f[i][j]表示以i为根节点的子树在背包容量为j的情况下价值的最大值

void dfs(int u)
{
    for(int j=v[u];j<=m;j++) f[u][j]=w[u];

    for(auto s:h[u])
    {
        dfs(s);
        for(int j=m;j>=v[u];j++)
            for(int k=0;k<=j-v[u];k++)
                f[u][j]=max(f[u][j],f[u][j-k]+f[u][k]);
    }
    return;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i]>>x;
        if(x==-1)
        {
            root=i;
            break;
        }
        h[i].push_back(x);
    }

    dfs(root);
    
    cout<<f[root][m]<<endl;

    return 0;
}