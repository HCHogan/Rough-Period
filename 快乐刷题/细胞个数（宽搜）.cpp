#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct Node
{
    int x;
    int y;
};
int np[4][2]=
{
    {0.1},
    {1,0},
    {0,-1},
    {-1,0}
};
int n,m,ans=0;
bool a[101][101],book[101][101];
void bfs(int x,int y)
{
    queue<Node> que;
    Node startnode;
    startnode.x=x;
    startnode.y=y;
    book[x][y]=1;
    que.push(startnode);
    ans++;
    while(!que.empty())
    {
        for(int i=0;i<4;i++)
        {
            int nx=que.front().x+a[i][0];
            int ny=que.front().y+a[i][1];
            if(a[nx][ny]&&!book[nx][ny])
            {
                book[nx][ny]=1;
                Node newnode;
                newnode.x=nx;
                newnode.y=ny;
                que.push(newnode);
                ans++;
            }
        }
        que.pop();
    }
    return;
}
int main()
{
    scanf("%d%d\n",&n,&m);
    //cin.getline(s,101);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            if(x!=0) a[i][j]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]&&!book[i][j]) bfs(i,j);
        }
    }
    cout<<ans<<endl;
}