#include<iostream>
using namespace std;
float ans=0;
int sum=0;
int main()
{
    int n;
    while(cin>>n)
    {
        sum=0;
        int a[n+1];
        int m=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            m=max(m,a[i]);
        }
        if(2*m>sum) ans=(sum-m+0.0);
        else{
            ans=(sum+0.0)/2;
        }
        printf("%.1f\n",ans);
    }
}