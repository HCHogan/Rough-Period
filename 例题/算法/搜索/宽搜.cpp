#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int x;
    int y;
    int step;     //到达当前点最少使用步数
};
int a[101][101];
bool book[101][101];

int n,m;
int start_x,start_y,end_x,end_y;
bool flag=false;

int np[4][2]=
{
    {0,1},     //向右
    {1,0},     //向下
    {0,-1},    //向左
    {-1,0}     //向上
};

queue<Node> que;                 //一个元素为Node的队列

void bfs()
{
    Node startnode;              //创建起点节点
    startnode.x=start_x;
    startnode.y=start_y;
    startnode.step=0;            //初始（1，1）位置步数为0
    book[start_x][start_y]=1;    //标记起点
    que.push(startnode);         //起点入队
    while(!que.empty())
    {
        for(int i=0;i<4;i++)
        {
            int nx=que.front().x+np[i][0];
            int ny=que.front().y+np[i][0];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!book[nx][ny]&&a[nx][ny]==0)
            {
                book[nx][ny]==1;
                Node new_node;
                new_node.x=nx;
                new_node.y=ny;
                new_node.step=que.front().step+1;
                que.push(new_node);
                if(nx==end_x&&ny==end_y)
                {
                    flag=1;
                    return;
                }
            }
        }
        que.pop();
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    cin>>start_x>>start_y>>end_x>>end_y;
    bfs();
    if(flag) cout<<que.back().step<<endl;
    else cout<<-1<<endl;
    return 0;
}