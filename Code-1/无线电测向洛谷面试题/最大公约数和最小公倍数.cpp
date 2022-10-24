#include<iostream>
using namespace std;
int isDivide(int a,int x)
{
    if(x%a==0) return 1;
    else return 0;
}

int minMult(int a,int b)
{
    int x=0;
    for(int i=a;i<=a*b;i++)
    {
        if(i%a==0&&i%b==0)
        {
            x=i;
            break;
        }
    }
    return x;
}

int maxDiv(int a,int b)
{
    int x=0;
    for(int i=a;i>0;i--)
    {
        if(a%i==0&&b%i==0)
        {
            x=i;
            break;
        }
    }
    return x;
}

int main(){
    int n,m;//n=3,m=60
    int num=0;
    cin>>n>>m;
    for(int i=n;i<m;i++)
    {
        for(int j=n;j<m&&j!=i;j++)
        {
            if(minMult(i,j)==m&&maxDiv(i,j)==n)
            {
                num++;
                cout<<i<<"  "<<j<<endl;
            }
        }
    }
    cout<<num;
}