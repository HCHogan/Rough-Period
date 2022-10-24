#include<iostream>
using namespace std;
#include<queue>
struct Node{
    int x;
    int y;
};
int a[101][101];
int np[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool book[101][101];
char b[101];
int n,m,ans=0;
void bfs(int x,int y);

int main()
{
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin.getline(b,101);
        for(int j=0;j<m;j++)
        {
            if(b[j]!='0') a[i][j]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1&&book[i][j]==false)
            {
                bfs(i,j);
            }
        }
    }
    cout<<ans;
}

void bfs(int x,int y)
{
    queue<Node> q;
    Node startNode={x,y};
    book[x][y]=true;
    q.push(startNode);
    ans++;
    while(!q.empty()){
        for(int i=0;i<4;i++)
        {
            int nx=q.front().x+np[i][0];
            int ny=q.front().y+np[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&book[nx][ny]==false&&a[nx][ny]==1)
            {
                Node newNode={nx,ny};
                book[nx][ny]=true;
                q.push(newNode);
            }
        }
        q.pop();
    }
    return;
}

// 4 10
// 0234500067
// 1034560500     
// 2045600671
// 0000000089