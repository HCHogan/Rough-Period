#include<iostream>
using namespace std;
int getNum(int a){
    int x[21];
    x[0]=1;x[1]=1;
    for(int i=0;i<a;i++){
        x[i+2]=x[i+1]+x[i];
    }
    return x[a-1];
}
int main(){
    int n,a[20];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<getNum(a[i])<<endl;
    }
}