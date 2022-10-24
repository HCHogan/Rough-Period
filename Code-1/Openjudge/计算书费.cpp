#include<iostream>
using namespace std;
int main(){
    double a[10],b[10],sum;
    a[0]=28.9;
    a[1]=32.7;
    a[2]=45.6;
    a[3]=78;
    a[4]=35;
    a[5]=86.2;
    a[6]=27.8;
    a[7]=43;
    a[8]=56;
    a[9]=65;
    for(int i=0;i<10;i++){
        cin>>b[i];
        sum+=a[i]*b[i];
    }
    cout<<sum;
}