#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
typedef long long LL;

int prim[N],vis[N],n,top;

int Eratosthenes(int n)     //时间复杂度O(nloglogn)
{
    top=0;
    for(LL i=2;i<=n;i++)
    {
        if(!vis[i]) prim[top++]=i;
        for(LL j=i*i;j<=n;j+=i)
        {
            vis[j]=1;
        }
    }
    return top;
}

int main()
{
    cin>>n;
    cout<<Eratosthenes(n)<<endl;
    return 0;
}