#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct Node{
    int x;
    int y;
    int step;
};
void bfs();
int n,m,start_x,start_y,end_x,end_y;
bool book[101][101];
int a[101][101];
bool flag=false;
int np[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
queue<Node> q;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>start_x>>start_y>>end_x>>end_y;
    bfs();
    if(flag) cout<<q.back().step;
    else cout<<"没有找到"<<endl;
}

void bfs()
{
    struct Node startNode={start_x,start_y,0};
    book[start_x][start_y]=true;
    q.push(startNode);
    while(!q.empty())
    {
        for(int i=0;i<4;i++)
        {
            int nx=q.front().x+np[i][0];
            int ny=q.front().y+np[i][1];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&book[nx][ny]==false&&a[nx][ny]!=1)
            {
                book[nx][ny]=true;//这我差点忘了
                Node newNode;
                newNode.x=nx;
                newNode.y=ny;
                newNode.step=q.front().step+1;
                q.push(newNode);
            }
            if(nx==end_x&&ny==end_y)
            {
                flag=true;
                return;
            }
        }
        q.pop();
    }
}

// 4 4
// 0 0 1 0
// 0 0 0 0
// 0 0 1 0
// 0 1 0 0
// 1 1 4 3