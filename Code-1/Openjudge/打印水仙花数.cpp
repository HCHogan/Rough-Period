#include<iostream>
using namespace std;
int main(){
    int i,a,b,c;
    for(i=100;i<1000;i++){
        a=i/100;
        b=(i-100*a)/10;
        c=i-100*a-10*b;
        if(i==a*a*a+b*b*b+c*c*c) cout<<i<<endl;
    }
}