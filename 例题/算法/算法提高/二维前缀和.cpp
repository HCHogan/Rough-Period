#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int a[N][N],s[N][N];
int n,m,q;
int main()
{
    cin>>n>>m>>q;
    memset(a,0,sizeof a);
    memset(s,0,sizeof s);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int t=s[x1][y1]-s[x2-1][y1]-s[x1][y2-1]+s[x2-1][y2-1];
        cout<<t<<endl;
    }
    
    return 0;
}
