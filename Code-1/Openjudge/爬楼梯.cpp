#include<iostream>
#include<cmath>
using namespace std;
int walk(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    else return walk(n-1)+walk(n-2);
}
int main(){
    int a;
    while(cin>>a){
        cout<<walk(a)<<endl;
    }
    
}