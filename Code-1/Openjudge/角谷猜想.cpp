#include<iostream>
using namespace std;
int main(){
    long long a,b,c;
    scanf("%lld",&a);
    while(a!=1){
        if(a%2!=0){
            b=a;
            a=a*3+1;
            cout<<b<<"*3+1="<<a<<endl;
        }    
        if(a%2==0){
            c=a;
            a=a/2;
            cout<<c<<"/2="<<a<<endl;
        }
    }
    if(a==1) cout<<"End"<<endl;
}