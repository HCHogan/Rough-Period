#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
//以01背包为例
int n,m;
int f[N],g[N];

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int w,v;
        cin>>w>>v;
        memcpy(f,g,sizeof g);
        for(int j=1;j<=m;j++) f[j]=max(f[j],g[j-v]+w);
    }
    cout<<f[m]<<endl;
    return 0;
}