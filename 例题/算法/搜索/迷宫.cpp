#include<iostream>
using namespace std;
int n,cnt=0;
bool a[10001][10001],book[10001][10001];
int dy[8]={-1,-1,0,1,1,1,0,-1},
    dx[8]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y)
{
    if(y==1&&x==n)
    {
        cnt++;
        return;
    }
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>n) continue;
        if(a[nx][ny]==0&&book[nx][ny]==0)
        {
            book[nx][ny]=1;
            dfs(nx,ny);
            book[nx][ny]=0;
        }
    }
    
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    book[1][1]=1;
    dfs(1,1);
    cout<<cnt;
}