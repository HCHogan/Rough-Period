#include<iostream>
using namespace std;
const int N=2e5+10,INF=0x3f3f3f3f;

long long a[N];
long long n,maxnum=-INF,res=0;
int sigh=0,T;

int main()
{
    cin>>T;
    while(T--)
    {
    sigh=0;
    res=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    maxnum=a[1];
    if(a[1]>0) sigh=1;
    else sigh=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        if(a[i]>0) t=1;
        else t=0;
        if(t!=sigh)
        {
            res=res+maxnum;
            maxnum=a[i];
            sigh=t;
        }
        else
        {
            maxnum=max(maxnum,a[i]);
        }
    }
    res=res+maxnum;
    cout<<res<<endl;
    }
    return 0;
}