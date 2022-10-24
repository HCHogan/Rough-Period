#include<iostream>
using namespace std;
int n,a[10001];
int ans=0;
int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int ave=sum/n;
    for(int i=1;i<=n-1;i++)
    {
        if(a[i]==ave) continue;
        int t=ave-a[i];
        a[i+1]-=t;
        ans++;
    }
    printf("%d",ans);
    return 0;
}