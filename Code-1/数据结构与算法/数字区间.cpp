#include<iostream>
using namespace std;
#include<algorithm>
int INF=0x3f3f3f3f;
struct range{
    int l,r;
    bool operator< (const range &x) const
    {
        return r<x.r;
    }
}range[100];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&range[i].l,&range[i].r);
    }
    sort(range+1,range+n+1);
    int ans=0,end=-INF;
    for(int i=1;i<=n;i++)
    {
        if(range[i].l>end)
        {
            end=range[i].r;
            ans++;
        }
    }
    cout<<ans;
}