#include<iostream>
using namespace std;
int main(){
    int a[10],b,i,j=0;
    for(i=0;i<10;i++){
        cin>>a[i];
    }
    cin>>b;
    for(i=0;i<10;i++){
        if(a[i]<=b+30) j++;
    }
    cout<<j;
}