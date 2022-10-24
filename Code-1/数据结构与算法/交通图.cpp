#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int map[9][9]={
    {0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0,1,1},
    {0,0,1,1,1,1,0,1,1},
    {0,0,1,1,0,0,1,1,1},
    {0,0,1,0,1,1,1,0,1},
    {0,1,1,0,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,0},
    {0,1,1,1,0,0,1,1,0},
    {0,1,1,1,1,0,0,0,1}
};
void bfs();
bool book[101];
int pre[101];
queue <int> q;

int main()
{
    bfs();
    int k=8;
    cout<<char(k+64);//先输出终点
    while(pre[k]!=0)
    {
        cout<<"-"<<char(pre[k]+64);
        k=pre[k];
    }
}

void bfs()
{
    q.push(1);
    book[1]=true;
    while(!q.empty())
    {
        int cur=q.front();
        for(int i=1;i<=8;i++)
        {
            if(map[cur][i]==0&&book[i]==false)
            {
                q.push(i);
                book[i]=true;
                pre[i]=cur;
            }
        }
        q.pop();
    }
}