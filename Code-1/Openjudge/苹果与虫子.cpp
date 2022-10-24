#include<iostream>
#include<math.h>
using namespace std;
int main(){
    float n,x,y,t,m;
    scanf("%f%f%f",&n,&x,&y);
    m=ceil(y/x);
    t=n-m;
    cout<<t;
}