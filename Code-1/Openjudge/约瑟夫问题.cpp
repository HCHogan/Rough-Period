#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int a[300]={1},n,p,i,m,count=0,j=0,x;
    cin>>n>>p>>m;
    count=n;
    while(count!=0){
        for(i=0;i<n;i++){
            x=(i+p)%n;
            if(a[x]!=0){
                j++;
                if(j==m){
                    a[x]=0;
                    if(i+p==8) {x=8;}
                    cout<<x;
                    count--;
                    if(count!=0) {cout<<",";}
                    j=0;
                }
                else continue;
            }
        }
    }
}