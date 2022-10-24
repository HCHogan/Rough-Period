#include<iostream>
using namespace std;
int main(){
    int a;
    scanf("%d",&a);
    if(a%400==0||(a%4==0&&a%100!=0)){
        cout<<"Y";
    }
        else cout<<"N";
}