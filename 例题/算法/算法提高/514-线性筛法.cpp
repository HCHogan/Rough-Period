#include<iostream>
#define int long long
using namespace std;
const int N=100000010,INF=0x3f3f3f3f;

int n,m;
int prim[N],top,vis[N];     //prim记录质数 vis记录合数

void get_prim(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            prim[top++]=i;
            cout<<i<<endl;
        }
        for(int j=0;i*prim[j]<=n;j++)
        {
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}

signed main()
{
    cin>>n;
    get_prim(n);
    return 0;
}
