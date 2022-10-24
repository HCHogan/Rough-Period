#include<iostream>
using namespace std;
void trans(int a)
{
    int n=a%2;
    if((a/2)==1)
    {
        cout<<"1";
    }
    else
    {
        trans(a/2);
    }
    cout<<n;
}
int main(){
    int n;
    cin>>n;
    trans(n);
}