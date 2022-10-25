#include<iostream>
#include<queue>
using namespace std;
const int N=10001;
int h[N],vis[N],nextNum,edge_sum=0,e,n;
struct Edge
{
    int nex=0;
    int to=0;
}edge[N];
void edge_add(int from,int to)
{
    edge[++edge_sum].nex=h[from];
    edge[edge_sum].to=to;
    h[from]=edge_sum;
}
void bfs(int i)
{
    cout<<i;
    vis[i]=1;
    queue<int> q;
    q.push(i);
    int cur,nextNum;
    while(!q.empty())
    {
        cur=q.front();
        nextNum=h[cur];
        while(nextNum)
        {
            if(!vis[nextNum])
            {
                cout<<edge[nextNum].to;
                vis[nextNum]=1;
                q.push(edge[nextNum].to);
            }
            nextNum=edge[nextNum].nex;
        }
        q.pop();
    }
}
int main()
{
    cin>>n>>e;
    memset(h,0,sizeof h);
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        edge_add(a,b);
    }
    for(int i=1;i<=e;i++) if(!vis[i]) bfs(i);
    return 0;
}