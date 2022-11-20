#include<iostream>
using namespace std;
const int N=1000010,INF=0x3f3f3f3f;

int n,a[N],b[N],temp[N];
bool book[N],flag=0,gflag=0;

void dfs(int u)
{
    if(u>n)
    {
        gflag=1;
        for(int i=1;i<=n;i++) cout<<b[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=1e6;i++)
    {
        int flag=0;
        for(int j=1;j<=n;j++)
        {
            if(book[i+a[j]]) flag=1;
        }
        if(flag==0)
        {
            for(int j=1;j<=n;j++)
            {
                book[i+a[j]]=1;
            }
            b[u]=i;
            dfs(u+1);
            if(gflag==1) return;
            for(int j=1;j<=n;j++)
            {
                book[i+a[j]]=0;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    return 0;
}