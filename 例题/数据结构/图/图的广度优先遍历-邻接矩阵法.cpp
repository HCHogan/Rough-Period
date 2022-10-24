#include<iostream>
using namespace std;
const int N=10001;
int nodesum,edgesum,que[N];
bool g[N][N],vi[N];
void bfs(int cur)
{
    int head=0,tail=1;
    que[0]=cur;
    while(head<tail)
    {
        for(int j=1;j<=nodesum;j++)
        {
            if(g[que[head]][j]&&!vi[j])
            {
                cout<<j<<" ";
                vi[j]=1;
                que[tail++]=j;
            }
        }
        head++;
    }
}
int main()
{
    cin>>nodesum>>edgesum;
    for(int i=1;i<=edgesum;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=1;
        //无向图g[b][a]=1;
    }
    for(int i=1;i<=nodesum;i++)
    {
        if(!vi[i]) bfs(i);
    }
    return 0;
}