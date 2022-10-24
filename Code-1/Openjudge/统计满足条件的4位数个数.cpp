#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,n,i,x[100],m,j=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x[i];
        a=x[i]/1000;
        b=(x[i]-1000*a)/100;
        c=(x[i]-1000*a-100*b)/10;
        d=x[i]-1000*a-100*b-10*c;
        m=d-a-b-c;
        if(m>0) j++;
    }
    cout<<j;
}