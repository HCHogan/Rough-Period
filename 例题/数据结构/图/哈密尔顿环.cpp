#include<iostream>
using namespace std;
const int N=10001;
int ans[N],node_sum,edge_sum,length,x;
bool g[N][N],nodex[N],vis[N];
void dfs(int last,int cur)
{
    ans[++length]=cur;
    vis[cur]=1;
    for(int i=1;i<=node_sum;i++)
    {
        if(g[cur][i]&&i==x&&i!=last)
        {
            ans[++length]=i;
            for(int j=1;j<=length;j++) cout<<ans[j]<<" ";
            cout<<endl;
            length--;
        }
        if(g[cur][i]&&!vis[i]&&nodex[i]) dfs(cur,i);    //为啥要加nodex？
        length--;
        vis[i]=0;
    }
}
int main()
{
    cin>>node_sum>>edge_sum;
    for(int i=1;i<=edge_sum;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=g[b][a]=1;
    }
    for(x=1;x<=node_sum;x++)
    {
        if(!nodex[x])
        {
            length=0;
            dfs(0,x);
            nodex[x]=1;
        }
    }
}