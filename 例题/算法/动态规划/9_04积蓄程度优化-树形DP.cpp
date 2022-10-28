#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int d[N],f[N],h[N],e[N],w[N],ne[N],deg[N];
int n,m,idx,ans;

int add(int from,int to,int wei)
{
    e[++idx]=to;
    w[idx]=wei;
    ne[idx]=h[from];
    h[from]=idx;
    deg[from]++;
    deg[to]++;
}

int dfsd(int u)
{
    int sum=0;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        sum+=min(w[i],dfsd(j));
    }
    d[u]=sum;
    if(deg[u]==1) return INF;//不能放在for前面 如果根结点度数为1 那就直接返回了
    return sum;
}

int dfsf(int u)
{
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(deg[u]==1) f[j]=d[j]+w[i];   //如果是叶子结点 那向上流量就是w[i]
        else f[j]=d[j]+min(w[i],f[u]-min(w[i],d[j]));
        //f[j]=d[j]+u[j];
        //u[j]=min(w[i],f[u]-D);
        //D=min(w[i],d[j]);
        dfsf(j);
    }
}

int main()
{
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        add(x,y,z);
        add(y,x,z);
    }

    dfsd(1);
    dfsf(1);

    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans<<endl;

    return 0;
}