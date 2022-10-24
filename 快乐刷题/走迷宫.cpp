#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
bool map[N][N],book[N][N],flag=0;
int col,lin,T,xa,xb,ya,yb,n;
int dx[]={0,1,0,-1},
    dy[]={1,0,-1,0};
void dfs(int x,int y)
{
    if(x==xa&&y==yb)
    {
        flag=1;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dx[i];
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(!book[nx][ny]&&!map[nx][ny])
        {
            book[nx][ny]=1;
            dfs(nx,ny);
            book[nx][ny]=0;
        }
    }
    return;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(map,0,sizeof map);
        memset(book,0,sizeof book);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                char c;
                cin>>c;
                if(c=='.') map[i][j]=0;
                if(c=='#') map[i][j]=1;
            }
        cin>>xa>>ya>>xb>>yb;
        dfs(xa,ya);
        if(flag) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}
