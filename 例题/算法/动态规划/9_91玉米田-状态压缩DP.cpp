#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int f[N][1<<14],s[1<<14],g[N];
int n,m,idx;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            g[i]=(g[i]<<1)+x;
        }
    }

    for(int i=1;i<=(1<<m);i++)
    {
        if(!(i&i>>1)) s[++idx]=i;       //选出一行没有连续两个1的方案
    }
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=idx;j++)
        {
            for(int k=1;k<=idx;k++)
            {
                if(!(s[j]&s[k])&&(s[j]&g[i])==s[j])
                    f[i][s[j]]+=f[i-1][s[k]];
            }
        }
    }
    cout<<f[n+1][0];

    return 0;
}