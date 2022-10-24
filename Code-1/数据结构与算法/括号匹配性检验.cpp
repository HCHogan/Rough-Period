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
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='('||a[i]=='[') s.push(a[i]);
        else if(a[i]==')')
        {
            if(s.empty()) {puts("Wrong");return 0;}
            else if(s.top()=='(') s.pop();
        }
        else if(a[i]==']')
        {
            if(s.empty()) {puts("Wrong");return 0;}
            else if(s.top()=='[') s.pop();
        }
    }
    if(s.size()==0) puts("OK");
    else puts("Wrong");
}