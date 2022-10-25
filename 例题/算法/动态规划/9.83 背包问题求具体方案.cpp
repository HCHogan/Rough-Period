#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int f[N][N];
int v[N],w[N],n,m;

void find_solu(int j)
{
    for(int i=1;i<=n;i++)
    {
        if(j>=v[i]&&f[i][j]==f[i][j-v[i]]+w[i])
        {
            cout<<i<<" ";
            j-=v[i];
        }
    }
    return;
}

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=max(f[i+1][j],f[i+1][j-v[i]]+w[i]);
        }
    }

    find_solu(m);

    return 0;
}