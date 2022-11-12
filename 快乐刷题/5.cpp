//21220513杨圣涵
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010;

int n,m;

int main()
{
    cin>>n>>m;
    char c;
    for(int i=1;i<=n;i++)
    {
        if(c=='R')cout<<"S"<<endl;
        else cout<<"P"<<endl;
        fflush(stdout);
        cin>>c;
    }
    return 0;
}