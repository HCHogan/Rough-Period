#include<iostream>
using namespace std;
const int N=10010;
int father[N],ene[N];
int n,m,res;

int find(int x)
{
    if(x!=father[x]) father[x]=find(father[x]);
    return x;
}

int merge(int x,int y)
{
    if(find(x)!=find(y)) father[x]=y;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x) merge(y,z);
        else
        {
            if(!ene[y]) ene[y]=z;
            if(!ene[z]) ene[z]=y;
            merge(father[y],ene[z]);
            merge(father[z],ene[y]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(father[i]==i) res++;
    }
    cout<<res<<endl;
    return 0;
}