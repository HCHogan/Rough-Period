#include<iostream>
#include<cstdio>
//21220513杨圣涵
using namespace std;
const int N=10010;
int a[N],n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if(n%2==1)
        cout<<a[(n-1)/2]<<endl;
    else printf("%.1lf\n",(double)(a[n/2-1]+a[(n/2)])/2);
    return 0;
}