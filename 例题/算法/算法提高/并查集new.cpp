#include<iostream>
#include<vector>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int fa[N],n,m;

vector<int>siz(N,1);

int find_raw(int x)
{
    if(x==fa[x]) return x;
    return find(fa[x]);
}

int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);       //这样做在find的时候就把集合合并了
}

void unionset_raw(int x,int y)
{
    fa[find(x)]=find(y);
}

void unionset(int x,int y)      //启发式合并 把小的插到大的里面去
{           //一般用不到 find的时候压缩路径已经足够好了
    int fax=find(x),fay=find(y);
    if(siz[fax]>siz[fay]) swap(fax,fay);
    fa[fax]=fay;
    siz[fay]+=siz[fax];
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        unionset(x,y);
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        cout<<find(x)<<endl;
    }
    return 0;
}