#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int m,n,count;
    cin>>m>>n;
    count=n-m+1;
    for(int i=m;i<=n;i++){
        if(i==1) count--;
        if(i==2) count=count;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0) {count--;
            break;
            }
        }
    }
    cout<<count;
}