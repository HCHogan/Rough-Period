#include<iostream>
using namespace std;
int main(){
    int a,i=1,n=0;
    cin>>a;
    while(a/i!=0){
        i=i*10;
        n++;
    }
    cout<<n;
}