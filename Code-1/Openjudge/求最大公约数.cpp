#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b;
    if(a<b){
        c=a;
        a=b;
        b=c;
    }
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    cout<<a;
}