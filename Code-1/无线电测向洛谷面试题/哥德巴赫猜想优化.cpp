#include<iostream>
#include<cmath>
using namespace std;
int m;
bool prime(int a)
{
    m=0;
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) m++;
    }
    if(m==0) return true;
    if(m!=0) return false;
}

int main()
{
    int n;
    cin>>n;
    for(int i=4;i<=n;i+=2)
    {
        for(int j=2;j<i;j++)
        {
            if(prime(j)&&prime(i-j))
            {
                cout<<i<<"="<<j<<"+"<<i-j<<endl;
                break;//因为只有两层循环，所以内层break可以直接跳出循环进入下一次外层循环
            }
        }
    }
}