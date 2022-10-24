#include<iostream>
using namespace std;
int main()
{
    float L=1.0,R=2.0,mid;
    while(L+0.000001<=R)
    {
        mid=(L+R)/2;
        if(mid*mid>2) R=mid;
        else L=mid;
    }
    printf("%lf",mid);
}