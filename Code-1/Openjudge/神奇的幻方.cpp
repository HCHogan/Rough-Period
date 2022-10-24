#include<iostream>
using namespace std;
int main(){
    int n,a[20][20]={0},x[41]={21},y[41]={21};
    cin>>n;
    for(int i=0;i<(2*n-1)*(2*n-1);i++){
        if(x[i]==21&&y[i]==21) {x[i+1]=0;y[i+1]=n-1;}
        else if(x[i]==0&&y[i]!=2*n-2) {x[i+1]=2*n-2;y[i+1]=y[i]+1;}
        else if(y[i]==2*n-2&&x[i]!=0) {x[i+1]=x[i]-1;y[i+1]=0;}
            else if(x[i]==0&&y[i]==2*n-2) {x[i+1]=x[i]+1;y[i+1]=y[i];}
        else if(a[x[i]-1][y[i]+1]!=0) {x[i+1]=x[i]+1;y[i+1]=y[i];}
        else if(a[x[i]-1][y[i]+1]==0) {x[i+1]=x[i]-1;y[i+1]=y[i]+1;}
        a[x[i+1]][y[i+1]]=i+1;
    }
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}