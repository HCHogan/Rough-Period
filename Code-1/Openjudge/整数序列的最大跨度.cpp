#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,a[1000],c=1000,d=0,i=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        d=max(d,a[i]);
        c=min(c,a[i]);
    }
    cout<<d-c;
}