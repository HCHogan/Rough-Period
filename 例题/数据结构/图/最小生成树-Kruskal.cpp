#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int n,m,res;
//并查集思想 先按边权从小到大排序 再依次合并（如果不构成回路的话）
struct Edge
{
    int a,b,w;
    bool operator< (const Edge& x) const
    {
        return w<x.w;
    }
}e[N];

int father[N];

int find(int x)
{
    if(x!=father[x]) father[x]=find(father[x]);
    return x;
}

int merge(int a,int b)
{
    int pa=find(a),pb=find(b);
    father[pa]=pb;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].a>>e[i].b>>e[i].w;
    }

    sort(e+1,e+1+m);
    
    for(int i=1;i<=m;i++)
    {
        int a=e[i].a,b=e[i].b,w=e[i].w;
        if(find(a)!=find(b))
        {
            merge(a,b);
            res+=w;
        }
    }
    
    cout<<res<<endl;
    return 0;
}