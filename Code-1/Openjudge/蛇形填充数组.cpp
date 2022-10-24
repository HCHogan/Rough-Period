#include<iostream>
using namespace std;
int main(){
    int a[10][10],n,i,j,m=2;
    cin>>n;
    a[0][0]=1;
    for(i=1;i<=2*n-1;i++){
        for(j=0;j<=i;j++){
            if(j<n&&i-j<n){
                if(i%2==1) a[j][i-j]=m++;
                else if(i%2==0) a[i-j][j]=m++;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}