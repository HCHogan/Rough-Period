#include<iostream>
using namespace std;
const int N=10010;

int f[N][1<<12],g[N];
int n,m,idx;
int s[1<<12],c[1<<12];

int main()
{
    cin>>n>>m;

    for(int i=1;i<=1<<m;i++)
    {
        if(!(i&i>>1)&&!(i&i>>2)) s[++idx]=i;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            g[i]=(g[i]<<j)+x;
        }
    }

    for(int i=1;i<=n+1;i++)
    {
        for(int a=1;a<=idx;a++)
        {
            int aa=s[a];
            for(int b=1;b<=idx;b++)
            {
                int bb=s[b];
                for(int c=1;c<=idx;c++)
                {
                    int cc=s[c];
                    if(!(aa&bb)&&!(aa&cc)&&!(bb&cc))
                        f[i][aa]+=f[i-1][bb]+f[i-1][cc];
                }
            }
        }
    }
    cout<<f[n+1][0]<<endl;
    return 0;
}