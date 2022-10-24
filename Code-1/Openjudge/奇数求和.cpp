#include<iostream>
using namespace std;
int main(){
    int a,b,n,sum;
    cin>>a>>b;
    if(a%2==0){
        a=a+1;
    }
    if(b%2==0){
        b=b-1;
    }
    n=(b-a)/2+1;
    sum=(a+b)*n/2;
    cout<<sum;
}