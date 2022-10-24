#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(a<60) cout<<"D";
    if(a>=60&&a<=74) cout<<"C";
    if(a>=75&&a<=89) cout<<"B";
    if(a>=90&&a<=100) cout<<"A";
}