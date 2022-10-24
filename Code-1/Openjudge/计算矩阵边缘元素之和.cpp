#include<iostream>
using namespace std;
int main(){
    int a[100][100],m,n,i,j,sum=0;
    cin>>m>>n;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++) cin>>a[i][j];
    }
    for(i=0;i<m;i++){
        sum=sum+a[i][0]+a[i][n-1];
    }
    for(i=0;i<n;i++){
        sum=sum+a[0][i]+a[m-1][i];
    }
    sum=sum-a[0][0]-a[0][n-1]-a[m-1][0]-a[m-1][n-1];
    cout<<sum;
}