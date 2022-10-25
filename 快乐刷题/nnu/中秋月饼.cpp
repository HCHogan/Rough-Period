#include<iostream>
#include<cmath>
using namespace std;
const int N=101,INF=0x3f3f3f3f;
bool g[N][N];
int n,x,y;
int mindis=INF;
int man(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
int calc(int x,int y)
{
    int res=0;
    for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
        {
            if(g[i][j]) res+=man(x,y,i,j);
        }
    return res;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        g[x][y]=1;
    }
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
            mindis=min(mindis,calc(i,j));
    }
    cout<<mindis<<endl;
    return 0;
}