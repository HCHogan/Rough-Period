#include<iostream>
using namespace std;
int n;
long long a[101];
int main()
{
    while(scanf("%d",&n),n)
    {
        a[0]=1;
        a[1]=2;
        a[2]=3;
        if(n==1)
        {
            cout<<"1";break;
        }
        if(n==2)
        {
            cout<<"2";break;
        }
        if(n==3) 
        {
            cout<<"3";break;
        }
        for(int i=0;i<n;i++)
        {
            a[i]=a[i-1]+a[i-2]+a[i-3];
        }
        cout<<a[n-1];
    }
}