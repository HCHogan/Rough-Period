#include<iostream>
using namespace std;
int main(){
    int a[100],i,n,temp;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n/2;i++){
        temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
    for(i=0;i<n;i++) cout<<a[i]<<" ";
}