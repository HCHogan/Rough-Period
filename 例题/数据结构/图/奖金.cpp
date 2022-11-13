#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int ne[N],to[N],h[N],idx,du[N];
int q[N],hh,tt;
int n,m,dis[N];

int add(int from,int des)
{
    to[++idx]=des;
    ne[idx]=h[from];
    h[from]=idx;
}

int toposort()
{
    for(int i=1;i<=n;i++)
        if(du[i]==0)
            q[tt++]=i;
    while(hh<tt)
    {
        int u=q[hh++];
        for(int i=h[u];~i;i=ne[i])
        {
            int v=to[i];
            if(--du[v]==0)
            {
                q[tt++]=v;
            }
        }
    }
    return tt==n;
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(b,a);
        du[a]++;
    }

    if(!toposort())
    {
        puts("Bad Xeg");
        return 0;
    }

    for(int i=1;i<=n;i++) dis[i]=100;

    for(int i=1;i<=n;i++)
    {
        int u=q[i];
        for(int j=h[u];~j;j=ne[j])
        {
            dis[to[j]]=max(dis[to[j]],dis[u]+1);
        }
    }

    int ans;
    for(int i=1;i<=n;i++) ans+=dis[i];
    cout<<ans<<endl;
    return 0;
}