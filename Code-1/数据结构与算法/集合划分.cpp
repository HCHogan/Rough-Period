#include<iostream>
using namespace std;
int work(int n,int k)
{
    if(n==k||n==1||k==1) return 1;
    //if(n<k||n==0) return 0;
    return work(n-1,k-1)+work(n-1,k)*k;
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<work(n,k);
}