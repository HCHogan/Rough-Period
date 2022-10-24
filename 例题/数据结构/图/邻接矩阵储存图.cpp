#include<iostream>
using namespace std;
const int N=10001;
int g[N][N];        //这样寸比较浪费空间
int n,m;        
int main()
{
    cin>>n>>m;   //n为点数,m为边数
    for(int i=1;i<=m;i++)           //无向图的建立
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=g[b][a]=1;
    }
    memset(g,0x3f,sizeof g); //memset是按照字节赋值的，所以用0x3f，一般无穷大喜欢用0x3f3f3f3f
    for(int i=1;i<=m;i++)           //无向图有权的建立
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=c;
    }
    for(int i=1;i<=m;i++)           //有向图的建立
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=1;
    }
    for(int i=1;i<=n;i++)           //输出图
    {
        for(int j=1;j<=n;j++)
        {
            cout<<g[i][j];
            //printf("%10d",g[i][j]);    每个数宽度是10 这样好看
        }
        puts("");
    }
}