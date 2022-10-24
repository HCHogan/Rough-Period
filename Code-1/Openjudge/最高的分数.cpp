#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int i,n,d,a[100];
    cin>>n;
    for(i=0,d=0;i<n;i++){
        cin>>a[i];
        while(i>=0&&i<=n){
            d=max(a[i],d);break;
        }
    }
    cout<<d;
}