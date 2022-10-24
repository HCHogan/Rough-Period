#include<iostream>
using namespace std;
int i,N,NA,NB,a[100],b[100],c=0,d=0,j,k;
int main(){
    cin>>N>>NA>>NB;
    for(i=0;i<NA;i++){
        cin>>a[i];
    }
    for(i=0;i<NB;i++){
        cin>>b[i];
    }
    for(i=0,c=0,d=0;i<N;i++){
        j=i % NA;
        k=i % NB;
        cout<<a[j]<<b[k];
        if(a[j]!=2&&b[k]!=2){
            if(a[j]>b[k]) c++;
            if(a[j]<b[k]) d++;
            if(a[j]==b[k]) {}
        }
        if(a[j]==2||b[k]==2){
            if(a[j]>b[k]) d++;
            if(a[j]<b[k])  c++;
            if(a[j]==b[k]) {}
        }
    if(c==d) {cout<<"draw";}
    if(c>d) {cout<<'A';}
    if(c<d) {cout<<'B';}
    cout<<c<<d;
    return 0;
    }
}