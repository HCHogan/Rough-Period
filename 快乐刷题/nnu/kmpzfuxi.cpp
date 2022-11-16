#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int z[N],n;
char str[N];

int main()
{
    cin>>n;
    cin>>str+1;
    for(int i=2,l,r=0;str[i];i++)
    {
        if(i<=r) z[i]=min(z[i-l+1],r-i+1);
        while(str[1+z[i]]==str[i+z[i]]) z[i]++;     //判断的是已匹配串的前面一格，同kmp
        if(i+z[i]-1>r) l=i,r=z[i]+i-1;      //指针永远指的是已匹配的最后一个，更新格子
    }
    for(int i=1;i<=n;i++) cout<<z[i]<<" ";
    return 0;
}