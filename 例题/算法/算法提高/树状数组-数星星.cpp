#include<iostream>
using namespace std;
const int N=32010;
int n;
int tr[N],level[N];
int lowbit(int x)
{
    return x&-x;
}
void update(int x,int t)
{
    while(x<=N)
    {
        tr[x]+=t;
        x+=lowbit(x);  
    }
}
int sum(int i)
{
    int res=0;
    while(i)
    {
        res+=tr[i];
        i-=lowbit(i);
    }
    return res;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        x++;
        level[sum(x)]++;
        update(x,1);
    }
    for(int i=1;i<=n;i++) cout<<level[i]<<endl;
    return 0;
}