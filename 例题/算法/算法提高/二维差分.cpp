#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int a[N][N],b[N][N];
int n,m,q;
void insert(int x1,int y1,int x2,int y2,int c)
{
    b[x1][y2]+=c;
    b[x1+1][y2]-=c;
    b[x2][y2+1]-=c;
    b[x2+1][y2+1]+=c;
}
int main()
{
    cin>>n>>m>>q;
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            insert(i,j,i,j,a[i][j]);
        }
    while(q--)
    {
        int x1,x2,y1,y2,c;;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            cout<<b[i][j];
        }
        puts("");
    }
    return 0;
}

