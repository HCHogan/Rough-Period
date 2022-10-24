#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a[10000],i,c=10001,b=-10001,n,m;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        c=min(c,a[i]);
        b=max(b,a[i]);
    }
    m=b-c;
    cout<<m;
}