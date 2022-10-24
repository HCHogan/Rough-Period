#include<iostream>
#include<stack>
#include<cstdio>
#include<string>
#include<unordered_map>
using namespace std;

string str;
bool legal=true;
stack<int> s_int;
stack<char> s_op;
unordered_map<char,int> pr{{'+',1},{'-',1},{'*',2},{'/',2}};

void calc()
{
    //
}

bool is_op(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/') return true;
    return false;
}

int main()
{
    cin>>str;
    for(int i=0;i<str.size()-1;i++)
    {
        int sum=0;
        if(str[i]=='(') sum++;
        if(str[i]==')') sum--;
    }
    for(int i=1;i<str.size()-1;i++)
    {
        if(
            (is_op(str[i])&&is_op(str[i-1])) ||
            (str[i-1]=='('&&is_op(str[i])) ||
            (is_op(str[i-1])&&str[i]==')') ||
            (isdigit(str[i-1])&&str[i]=='(') ||
            (isdigit(str[i])&&str[i-1]==')')
        ){
            legal=false;
        }
    }
}