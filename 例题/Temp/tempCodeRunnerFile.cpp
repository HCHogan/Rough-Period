#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[10001],f[10001],T;
int main()
{
    cin>>T;
    while(T--)
    {
        int len=1;
        memset(a,0,sizeof a);
        memset(f,0,sizeof f);
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        f[1]=a[1];
        for(int i=2;i<=2;i++)
        {
            if(a[i]>f[len]) f[++len]=a[i];
            else
            {
                int *p=upper_bound(f+1,f+len+1,a[i]);
                *p=a[i];
            }
            cout<<len<<endl;
        }
    }
}