#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int n,m;
int f[N][1<<12],st[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=1<<n;i++)
    {
        int cnt=0;
        st[i]=true;
        for(int j=0;j<n;j++)
        {
            if(i>>j&1)
            {
                if(cnt&1)
                {
                    st[i]=false;
                    break;
                }
            }
            else cnt++;
        }
        if(cnt&1) st[i]=false;
    }
    f[0][0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int a=1;a<=1<<n&&st[a];a++)
        {
            for(int b=1;b<=1<<n&&st[b];b++)
            {
                if(st[a|b]&&(a&b)==0)
                {
                    f[i][a]+=f[i-1][b];
                }
            }
        }
    }
    cout<<f[m][0]<<endl;
}