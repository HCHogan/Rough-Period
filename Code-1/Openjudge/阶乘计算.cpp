#include<iostream>
using namespace std;
int Fac(int n){
    int a=1;
    for(int i=1;i<=n;i++){
        a*=i;
    }
    return a;
}
int main(){
    int n;
    cin>>n;
    cout<<Fac(n);
}