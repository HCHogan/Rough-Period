#include<iostream>
using namespace std;
int main(){
    int a[100],n,i,x=0,y=0,z=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1) x++;
        if(a[i]==5) y++;
        if(a[i]==10) z++;
    }
    cout<<x<<endl<<y<<endl<<z;
}