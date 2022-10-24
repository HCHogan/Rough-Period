#include<iostream>
using namespace std;
int main(){
    double a[10000],n,x,sum=0;
    int i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
    }
    x=sum/n;
    printf("%.0f %.5lf",sum,x);
}