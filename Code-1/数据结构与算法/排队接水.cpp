#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> a[1010];
int n;
float sum=0,t=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        t+=a[i-1].first;
        sum+=t;
        //cout<<a[i-1].second<<" ";
    }
    //cout<<a[10].second<<" ";
    for(int i=1;i<=n;i++) cout<<a[i].second<<" ";
    cout<<endl;
    float ave=sum/(n+0.0);
    printf("%.2lf",sum/n);
}