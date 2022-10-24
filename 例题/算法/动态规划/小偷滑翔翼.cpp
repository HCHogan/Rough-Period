#include<iostream>
#include<cstring>
const int N=10001;
int T,f[N],a[N],ans,n;    //f[i]是到第i个数位置最长子序列长度
using namespace std;
int main()
{
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof a);
        memset(f,0,sizeof f);
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
                if(a[i]>a[j])
                    f[i]=max(f[i],f[j]+1);
            ans=max(f[i],ans);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
                if(a[i]<a[j])
                    f[i]=max(f[i],f[j]+1);
            ans=max(f[i],ans);
        }
        cout<<ans;
    }
    return 0;
}
