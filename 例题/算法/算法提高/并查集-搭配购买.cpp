#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
int worth[N],price[N],f[N];
int father[N];
int n,m,w;

int find(int x)
{
    if(x!=father[x]) father[x]=find(father[x]);
    return x;
}

int merge(int a,int b)
{
    int pa=find(a),pb=find(b);
    if(pa!=pb)
    {
        worth[pa]+=worth[pb];
        price[pa]+=price[pb];
        father[pb]=pa;
    }
}

int main()
{
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>price[i]>>worth[i];
    }
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }

    for(int i=1;i<=n;i++)
    {
        if(father[i]!=i) continue;
        for(int j=w;j>=price[i];j--)
        {
            f[j]=max(f[j],f[j-price[i]]+worth[i]);
        }
    }

    cout<<f[w]<<endl;
}