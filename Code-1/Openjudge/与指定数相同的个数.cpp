#include<iostream>
using namespace std;
int main(){
    int n,a[100],i,m,j=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(i=0;i<n;i++){
        if(a[i]==m) j++;
    }
    cout<<j;
}