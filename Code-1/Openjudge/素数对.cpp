#include<iostream>
#include<cmath>
using namespace std;
int cnt=0,m=0;
int Judge(int a){
    if(a==1) return 0;
    if(a==2) return 1;
    for(int j=2;j<=sqrt(a);j++){
        if(a%j==0) return 0;
    }
    return 1;
}
int main(){
    int n,a,b;
    cin>>n;
    for(int i=2;i<=n-2;i++){
        if(Judge(i)&&Judge(i+2)) {
            cout<<i<<" "<<i+2<<endl;
            m++;
        }
    }
    if(m==0) cout<<"empty";
}