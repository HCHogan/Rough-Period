#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int h[N],to[N],w[N],ne[N],idx;
int f[N][2];        //f[i][1]表示以
int n;

void add(int from,int t)
{
    ne[++idx]=h[from];
    to[idx]=t;
    h[from]=idx;
}

void dfs(int u)
{
    f[u][1]+=w[u];
    for(int i=h[u];~i;i=ne[i])
    {
        dfs(to[i]);
        f[u][1]+=f[to[i]][0];
        f[u][0]+=max(f[to[i]][1],f[to[i]][0]);
    }
}

int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        int from,to;
        cin>>from>>to;
        add(from,to);
    }
}