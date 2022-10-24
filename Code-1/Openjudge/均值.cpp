#include<iostream>
using namespace std;
int main(){
    double a[1000],n,x,sum=0;
    int i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
    }
    x=sum/n;
    printf("%.4lf",x);
}