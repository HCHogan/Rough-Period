#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int z[N],idx,n;
char str[N];

int main()
{
    cin>>n;
    cin>>str+1;
    str[1]=n;
    for(int i=2,l,r=0;str[i];i++)
    {
        if(i<=r) z[i]=min(z[i-l+1],r-i+1);  //用偏移+其实地址思考比较好
        while(str[1+z[i]]==str[i+z[i]]) z[i]++;
        if(i+z[i]-1) l=i,r=i+z[i]-1;        //i是起始地址 偏移量是z[i]-1
    }       //因为整个字符串是从1开始的 //指针永远指的是已匹配的最后一个，更新格子
    //判断的是已匹配串的前面一格，同kmp
//和kmp一样 本质上都是利用已匹配的旧状态加速新状态 利用信息
//z[i]是公共前缀长度 盒内加速 盒子外暴力