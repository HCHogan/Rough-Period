#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,n,sum;
    cin>>a>>b;
    if(a%17==0){
        c=a;
    }
    else c=a+17-(a%17);
    if(b%17==0){
        d=b;
    }
    else d=b-b%17;
    n=(d-c)/17+1;
    sum=(c+d)*n/2;
    cout<<sum;
}