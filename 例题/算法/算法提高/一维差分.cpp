#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
int n,m;
int a[N],b[N];      //a是原始数组，b是差分数组(导)
void insert(int           l,int r,int c)      //意义：把l和r(闭区间)中的元素每个都加c
{
    b[l]+=c;
    b[r+1]-=c;
}
int main()
{
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int c;
        cin>>c;
        insert(i,i,c);      //把i处的元素+c
    }
    for(int i=1;i<=m;i++)
    {
        int l,r,c;
        cin>>l>>r>>c;
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+b[i];
    }
    cout<<a[n];
}