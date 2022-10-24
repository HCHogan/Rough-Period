#include<iostream>
using namespace std;
int main(){
    int num=0,m,k,i,x,u;
    cin>>m>>k;
    u=m%19;
    for(i=0;i<6;i++){
        x=m%10;
        m=m/10;
        if(x==3) num++;
    }
    if(u==0&&num==k) cout<<"YES";
    else cout<<"NO";
}