#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;
int main()
{
    stack<char>s;
    string a;
    cin>>a;
    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i]=='(') s.push(a[i]);
        else if(a[i]==')')
        {
            if(s.empty()) {puts("NO");return 0;}
            else if(s.top()=='(') s.pop();
        }
    }
    if(s.size()==0) puts("YES");
    else puts("NO");
}