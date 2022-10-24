#include<iostream>
using namespace std;
int main()
{
    int a[10];
    for(int i=0;i<10;i++)
    {
        a[i]=i;
    }
    int x=(1+2)>>1;
    int ref=a[(1+2)/2];
    cout<<a[x]<<endl;
    cout<<a[];
    cout<<ref;
}