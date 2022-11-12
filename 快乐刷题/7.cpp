//21220513杨圣涵
#include<iostream>
#include<cstdio>

using namespace std;
const int N=2010;

int n;
int a[N];

int main()
{
    cin>>n;
    a[1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            printf("? %d %d",i,j);
            fflush(stdout);
            int t;
            cin>>t;
            a[j]+=t+a[i];
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=i) printf("! %")
    }

}