#include<iostream>
using namespace std;
const int N=10001;
int a[N],b[N],n,len=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>b[i-1]) b[++len]=a[i];
        else
        {
            int *p=upper_bound(a+1,a+i+1,a[i]);
            *p=a[i];
        }
    }
    cout<<len<<endl;
    for(int i=1;i<=len;i++) cout<<b[i];
    return 0;
}