#include<iostream>
#include<string>
using namespace std;
//一件比较令人难以接受的事情就是这道题是有顺序的。
//也就是说只要从左往右或者从右往左翻转硬币，那么一定可以成功，除非题目无解。
//因为当你模仿着下面的最终形态来翻硬币时你保证了翻过的硬币都一模一样了。
//这个时候如果后面不一样那就一定无解
//比如
//******ooo
//*********
//当然这个程序只允许有解的情况出现，所以甚至有恃无恐地让i<size-1。
//那么只要一个循环遍历模拟过程就能解决。
//去你奶奶的

const int N=110;

int ans=0;
int main()
{
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i]!=b[i])
        {
            ans++;
            if(a[i]=='*') a[i]='o';
            else a[i]='*';
            if(a[i+1]=='*') a[i+1]='o';
            else a[i+1]='*';
        }
    }
    cout<<ans;
}