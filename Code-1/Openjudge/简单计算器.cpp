#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    char m;
    cin>>a>>b>>m;
    switch (m)
    {
    case '+':c=a+b;cout<<c;break;
    case '-':c=a-b;cout<<c;break;
    case '*':c=a*b;cout<<c;break;
    case '/':if(b==0) {cout<<"Divided by zero!"<<endl;}
             if(b!=0) {c=a/b;cout<<c;}
             break;
    default:cout<<"Invalid operator!"<<endl;break;
    }
}