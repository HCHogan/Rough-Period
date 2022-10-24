#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[5][5],i,j,m,n,x,y,c,d,k,s,w=0,count=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++) cin>>a[i][j];
    }
    for(i=0;i<5;i++){
        x=a[i][0];
        for(j=0;j<5;j++){
            x=max(x,a[i][j]);
        }
        for(j=0;j<5;j++){
            if(x==a[i][j]) {c=i;d=j;}
        }   
        for(k=0;k<5;k++){
                if(x>a[k][d]){
                    w=1;
                    break;
                }
            }
        if(w==0) cout<<c+1<<" "<<d+1<<" "<<x;count++;
    }
    if(count==0) cout<<"not found";
    return 0;
}