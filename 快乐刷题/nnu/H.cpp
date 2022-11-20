#include<iostream>
using namespace std;
const int N=1;

int a,b,k,T;
bool isfind=0;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>k;
        for(int i=1;i*k<1<<30;i++)
        {
            for(int j=1;j*k<1<<30;j++)
                if(((k*i)xor(a))==((k*j)xor(b)))
                {
                    printf("%d",(k*i)^(a));
                    isfind=1;
                    break;
                }
            if(isfind==1) break;

        }
    }
}