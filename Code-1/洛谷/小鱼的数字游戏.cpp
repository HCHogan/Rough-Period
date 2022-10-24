#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,i=0;
    int a[100]={0};
    while(1)
    {
        cin>>n;
        if(n==0) break;
        a[i++]=n;
    }
    for(int j=99;j>=0;j--)
    {
        if(a[j]) cout<<a[j]<<" ";
    }
}