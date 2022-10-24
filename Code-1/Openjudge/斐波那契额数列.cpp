#include<iostream>
using namespace std;
int main(){
    int i,a[46],n;
    cin>>n;
    a[0]=1;
    a[1]=1;
    for(i=2;i<=n-1;i++){
        a[i]=a[i-1]+a[i-2];
    }
    cout<<a[n-1];
}