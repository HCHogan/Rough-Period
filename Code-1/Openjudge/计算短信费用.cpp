#include<iostream>
using namespace std;
int main(){
    int n,x,a;
    cin>>n;
    float sum=0;
    for(int i=0;i<n;i++){
        cin>>a;
        x=(a-1)/70+1;
        sum+=x*0.1;
    }
    printf("%.1f",sum);
}