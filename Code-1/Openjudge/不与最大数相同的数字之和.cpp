#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a[100],i,n,b=-1000001,sum=0,j=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        b=max(b,a[i]);
    }
    for(i=0;i<n;i++){
        sum+=a[i];
        if(a[i]==b) j++;
    }
    sum=sum-b*j;
    cout<<sum;
}