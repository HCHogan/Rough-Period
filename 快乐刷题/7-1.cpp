//21220513杨圣涵
#include<iostream>
#include<cstdio>
using namespace std;
const int N=2010;

int a[N],n;
int b[N];
int ans1,ans2;

int main()
{
    cin>>n;
    a[1]=0;
    for(int i=2;i<=n;i++)
    {
        printf("? 1 %d\n",i);
        fflush(stdout);
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) a[i]=-a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        b[n-i+1]=-a[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]!=1)
        {
            ans1=i;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(b[i]-b[i-1]!=1)
        {
            ans2=i;
        }
    }
    printf("! %d %d",ans1,ans2);
    return 0;
}