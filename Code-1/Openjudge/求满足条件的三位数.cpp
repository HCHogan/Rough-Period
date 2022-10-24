#include<iostream>
using namespace std;
int Square(int a){
    for(int j=10;j<32;j++){
        if(a==j*j) {return 1;}
    }
    return 0;
}

int Same(int a){
    int x,y,z;
    x=a/100;
    z=a%10;
    y=(a/10)%10;
    if(x==y||y==z||z==x) {return 1;}
    else return 0;
}

int main(){
    int n,a,b,x,y,z,cnt=0,m[100];
    for(int i=100;i<=999;i++){
        if(Same(i)&&Square(i)) {
            cnt++;
            m[cnt]=i;
            }
    }
    cin>>n;
    cout<<m[n];
}