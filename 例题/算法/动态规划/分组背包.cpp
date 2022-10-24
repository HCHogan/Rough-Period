#include<iostream>
using namespace std;
const int N=10001;
int value[N][N],space[N][N],group[N],f[N];
int main()
{
    memset(f,0,sizeof f);
    memset(group,0,sizeof group);
    memset(value,0,sizeof value);
    memset(space,0,sizeof space);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        group[z]++;
        value[z][group[z]]=x;
        space[z][group[z]]=y;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            for(int k=1;k<=group[i];k++)
            {
                f[j]=max(f[j],value[i][k]+f[j-space[i][k]]);
            }
        }
    }
    cout<<f[m];
    return 0;
}