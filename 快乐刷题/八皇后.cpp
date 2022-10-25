#include<iostream>
#include<cstring>
using namespace std;
bool map[9][9],col[9];
int cnt=0,dp[9],dm[9];

void printM()
{
    cout<<"No."<<++cnt<<endl;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++) cout<<map[i][j];
        cout<<endl;
    }
}
bool judgeisok(int u,int i)
{
    bool check=1;
    for(int j=1;j<=u;j++) if(u+i==dp[j]||u-i==dm[j]) check=0;
    return check;
}
void dfs(int u)
{
    if(u>8)
    {
        printM();
        return;
    }
    for(int i=1;i<=8;i++)
    {
        if(!col[i]&&judgeisok(u,i))
        {
            col[i]=1;
            map[u][i]=1;
            dp[u]=u+i;
            dm[u]=u-i;
            dfs(u+1);
            col[i]=0;
            map[u][i]=0;
        }
    }
    return;
}
int main()
{
    memset(map,0,sizeof map);
    memset(col,0,sizeof col);
    memset(dm,0x3f,sizeof dm);
    memset(dp,0x3f,sizeof dp);
    dfs(1);
    return 0;
}