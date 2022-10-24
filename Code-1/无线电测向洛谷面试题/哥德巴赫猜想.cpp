#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a[10000],b,k=0,n,x;
    cin>>b;
    for(int i=2;i<10000;i++)
    {
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0) n++;
        }
        if(n==0)
        {
            a[k]=i;
            k++;
        }
        n=0;
    }
    for(int i=1;i<=(b-2)/2;i++)
    {
        int ret=2*i+2;
        for(int j=0;j<k;j++)
        {
            x=0;
            for(int m=0;m<k;m++)
            {
                if(ret==a[j]+a[m])
                {
                    cout<<ret<<"="<<a[j]<<"+"<<a[m]<<endl;
                    x++;
                }
            }
            if(x!=0) break;
        }
    }
}