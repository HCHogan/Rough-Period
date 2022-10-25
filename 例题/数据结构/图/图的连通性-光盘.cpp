#include<iostream>
using namespace std;
const int N=10001;
bool g[N][N];
int node_sum,father[N],ans=0;    //第i个节点所在组的老大是谁
int main()
{
    cin>>node_sum;
    memset(g,0,sizeof g);
    for(int i=1;i<=node_sum;i++)
    {
        int t;
        while(scanf("%d",&t),t) g[i][t]=1;
    }
    for(int k=1;k<=node_sum;k++)
    {
        for(int i=1;i<=node_sum;i++)
        {
            for(int j=1;j<=node_sum;j++)
            {
                if(i!=j&&i!=k&&j!=k)
                    g[i][j]=g[i][j]||(g[k][j]&&g[k][i]);
            }
        }
    }
    for(int i=1;i<=node_sum;i++) father[i]=i;
    for(int i=1;i<=node_sum;i++)
    {
        for(int j=1;j<=node_sum;j++)
            if(g[i][j]) father[j]=father[i];
    }
    for(int i=1;i<=node_sum;i++) if(father[i]==i) ans++;
    cout<<ans<<endl;
    return 0;
}