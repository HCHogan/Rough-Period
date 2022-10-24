#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
int a[N][N],s[N][N];
int n,m;
void insert(int x1,int y1,int x2,int y2)
{
    a[x1][y1]+=1;
    a[x1][y2+1]-=1;
    a[x2+1][y1]-=1;
    a[x2+1][y2+1]+=1;
}
int main()
{
    cin>>n;
    memset(a,0,sizeof a);
    memset(s,0,sizeof s);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int x,y;
            insert(x,y,x,y);
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            printf("x=%d,y=%d = %d",i,j,s[i][j]);
        }
        puts("");
    }
    return 0;
}