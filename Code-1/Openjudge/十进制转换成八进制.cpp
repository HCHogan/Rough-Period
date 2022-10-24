#include<iostream>
#include<math.h>
using namespace std;
long int m[10],sum=0;
int count(long int a){
    for(int i=6;i>=0;i--){
        m[i]=a/pow(8,i);
        a=a-m[i]*pow(8,i);
    }
    for(int i=6;i>=0;i--){
        sum+=m[i]*pow(10,i);
    }
    return sum;
}

int main(){
    long int n;
    cin>>n;
    cout<<count(n);
}