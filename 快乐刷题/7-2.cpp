//21220513杨圣涵
#include<iostream>
#include<cstdio>
using namespace std;
const int N=20100;

int a[N],n;
int ans1;

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
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]!=1)
        {
            ans1=i;
        }
    }
    printf("! %d %d",ans1,n-ans1+2);
    return 0;
}