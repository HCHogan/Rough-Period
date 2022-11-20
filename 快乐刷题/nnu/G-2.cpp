#include<iostream>
using namespace std;
const int N=2e5+10;

long long n,a[N],res,maxnum;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        maxnum=a[1];
        int last=0,res=0;
        if(a[1]>0) last=1;
        else last=0;
        for(int i=1;i<=n;i++)
        {
            int x=a[i];
            int t;
            if(x>0) t=1;
            else t=-1;
            if(last==t)
            {
                maxnum=max(maxnum,a[i]);
            }
            else
            {
                res+=maxnum;
                maxnum=a[i];
                last=t;
            }
        }
        res+=maxnum;
        cout<<res<<endl;
    }
}