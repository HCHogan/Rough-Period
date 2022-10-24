#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double sum=0;
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++){
        sum=sum+pow(-1,i-1)*1/i;
    }
    printf("%.4lf",sum);
}