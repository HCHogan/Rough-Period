#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;

int n,m;
int father[N];
int cnt[N];
int x,y;

int find(int x)
{
    if(father[x]!=x) father[x]=find(father[x]);
    return x;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) father[i]=i;
    while(m--)
    {
        cin>>x>>y;
        int px=find(x),py=find(y);
        if(px!=py) father[px]=py;
    }
}