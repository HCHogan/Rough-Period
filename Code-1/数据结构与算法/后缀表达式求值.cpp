#include<iostream>
#include<stack>
#include<cstdio>
#include<string>
using namespace std;
typedef long long LL;
int main()
{
    stack<int>stk;
    string str;
    getline(cin,str);
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i]=='+')
        {
            LL t=stk.top();
            stk.pop();
            stk.top()+=t;
        }
        else if(str[i]=='-')
        {
            LL t=stk.top();
            stk.pop();
            stk.top()-=t;
        }
        else if(str[i]=='*')
        {
            LL t=stk.top();
            stk.pop();
            stk.top()*=t;
        }
        else if(str[i]=='/')
        {
            LL t=stk.top();
            stk.pop();
            stk.top()/=t;
        }
        else if(isdigit(str[i]))
        {
            LL x=0;
            while(str[i]!=' ')
            {
                x=x*10+str[i++]-'0';
                stk.push(x);
            }
        }
    }
    cout<<stk.top();
}