//21220513
#include<iostream>
using namespace std;
const int N=1e9+10,INF=0x3f3f3f3f;

int a,b,n,t[N],x=n,cnt=0,num[N];
int da,db;

int dfs(int u,int cnt,int left)
{
    int x=t[u];
    if(x==0&&num[u-1]==0)
    {
        num[u]=0;
        
    }
}

int main()
{
    cin>>n>>a>>b;
    db=max(a,b);
    da=min(a,b);
    for(int i=0;i<=9;i++)
    {
        t[9-i]=x%10;
        if(t[9-i]!=0) cnt++;
        x/=10;
    }
    int init=9-cnt+2;
    if(cnt%2==0)
    {
        dfs(0,cnt,cnt/2);
    }
    return 0;
}