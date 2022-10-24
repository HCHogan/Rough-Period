#include<iostream>
using namespace std;
int main(){
    double a,b,x;
    cin>>x;
    a=x/1.2;
    b=50+x/3;
    if(a>b)
      cout<<"Bike";
    if(a==b)
      cout<<"All";
    if(a<b)
      cout<<"Walk";

}