#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int son[N][2],a[N],b[N],n,m,idx;
int maxnum=-INF;

void insert(int x)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int j=x>>i&1;
        if(!son[p][j]) son[p][j]=++idx;
        p=son[p][j];
    }
}

int query(int x)
{
    int p=0,res=0;
    for(int i=30;i>=0;i--)
    {
        int j=x>>i&1;
        if(son[p][!j])      //如果这位上与j相反的那个数存在 走那条路
        {
            res+=1<<i;
            p=son[p][!j];
        }
        else                //不存在就走这条路
        {
            p=son[p][j];
        }
    }
    return res;
}

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        insert(x);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        maxnum=max(maxnum,query(x));
    }
    return 0;       //是件复杂度为O(31n)<暴力的n方 能过
                    //因为每次走的时候都尽量让和问的那个数或出来的最大
}