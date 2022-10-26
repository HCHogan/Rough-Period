#include<cstring>
#include<cstdio>
#include<complex>
#include<iostream>
using namespace std;

class MyString
{
public:
    MyString(const char* cstr=0);
    MyString(const MyString& mstr);
    MyString& operator=(const MyString& cmystr)
    {
        if(this==&cmystr) return *this;
        delete[] this->m_mystr;
        m_mystr=new char[strlen(cmystr.m_mystr)+1];
        strcpy(m_mystr,cmystr.m_mystr);
        return *this;
    }
    ~MyString();
    char* get_c_mystr() const
    {
        return m_mystr;
    }
private:
    char *m_mystr;
};

inline MyString::MyString(const char* cstr=0)
{
    if(cstr)
    {
        m_mystr=new char[strlen(cstr)+1];       //最后要放'\0' 所以+1 
        strcpy(m_mystr,cstr);
    }
    else
    {
        m_mystr=new char[1];
        *m_mystr='\0';
    }
}

inline MyString::~MyString()
{
    delete[] m_mystr;
}

int main()
{
    string str1;
    string str2("hello");
    string str3(str2);
    cout<<sizeof(string)<<endl;
    return 0;
}