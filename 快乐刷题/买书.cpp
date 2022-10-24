#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
int f[N],money,value[5]={0,10,20,50,100};
int main()
{
    cin>>money;
    memset(f,0,sizeof f);
    f[0]=1;
    for(int i=1;i<=4;i++)
    {
        for(int j=value[i];j<=money;j++)
            f[j]+=f[j-value[i]];
    }
    cout<<f[money];
    return 0;
}