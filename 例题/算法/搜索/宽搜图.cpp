#include<iostream>
#include<queue>
using namespace std;
int map[9][9];
bool book[101];
int pre[101];    //保存每一个节点的前驱节点

queue<int> que;
void bfs()
{
    que.push(1);
    book[1]=1;
    while(!que.empty())
    {
        int cur=que.front();
        for(int i=1;i<=8;i++)
        {
            if(map[cur][i]==0&&!book[i])
            {
                book[i]=1;
                que.push(i);
                pre[i]=cur;
            }
        }
        que.pop();
    }
}
int main()
{
    for(int i=0;i<=9;i++)
    for(int j=0;j<=9;j++)
    cin>>map[i][j];
    bfs();
    int k=8;
    cout<<char(k+64);
    while(pre[k])
    {
        cout<<"-"<<char(pre);
        k=pre[k];
    }
    return 0;
}