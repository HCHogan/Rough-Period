#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main()
{
    int n,index=1;
    cin>>n;
    int a[n];
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        while(index<=a[i]) s.push(index++);
        if(s.top()==a[i]) s.pop();
        else {puts("NO");return 0;}
    }
    puts("YES");
}