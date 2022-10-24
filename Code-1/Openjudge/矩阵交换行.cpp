#include<iostream>
using namespace std;
int main(){
    int a[6][6],i,j,temp,m,n;
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++) cin>>a[i][j];
    }
    cin>>m>>n;
    for(i=1;i<=5;i++){
        temp=a[m][i];
        a[m][i]=a[n][i];
        a[n][i]=temp;
    }
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++) {printf("%d ",a[i][j]);}
        printf("\n");
    }
}