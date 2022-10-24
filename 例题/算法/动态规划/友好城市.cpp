#include<iostream>
using namespace std;
const int N=10001;
int n,f[N],ans=0;
typedef pair<int,int> PII;
PII q[N];
int cmp(PII x,PII y)
{
    return x.first<y.first;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>q[i].first>>q[i].second;
    sort(q+1,q+1+n,cmp);
    f[1]=1;
    for(int i=1;i<=n;i++)        //找最大上升子连续序列
    {
        f[i]=1;
        if(q[i].second>q[i-1].second)
            f[i]=max(f[i],f[i-1]+1);
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}