#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int w[N],n,m,h[N];
struct Node
{
    int key,a,b;
}dat[N];

int find(int x)
{
    int k=(x%N+N)%N;
    while(h[k]!=INF&&h[k]!=x)
    {
        k++;
        if(k==N) k=0;
    }
    return k;
}

int main()
{
    cin>>n;
    memset(h,0x3f,sizeof h);
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            Node newnode={abs(w[i]+w[j]),w[i],w[j]};
            h[find(newnode.key)]=newnode.key;
            dat[find(newnode.key)]=newnode;
        }
    }

    bool isFind=0;
    int maxv=-INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            Node newnode={abs(w[i]-w[j]),w[i],w[j]};
            int k=find(newnode.key);
            if(h[k]==INF) continue;
            int a=dat[k].a,b=dat[k].b;
            if(a!=i&&a!=j&&b!=i&&b!=j)
            {
                isFind=1;
                if(w[i]==w[j]+a+b) maxv=max(maxv,w[i]);
                if(w[j]==w[i]+a+b) maxv=max(maxv,w[j]);
            }
        }
    }
    if(isFind) cout<<maxv<<endl;
    else puts("No Solution");
}