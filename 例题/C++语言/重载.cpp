#include<iostream>
#include<cstring>
using namespace std;

class MyInteger
{
    friend ostream& operator<< (ostream& cout, MyInteger inte);
public:
    MyInteger();
    MyInteger(int age);
    ~MyInteger();
    MyInteger& operator++ ()
    {
        m_Num++;
        return *this;
    }
    MyInteger operator++ (int)
    {
        MyInteger temp = *this;
        this->m_Num++;
        return temp;
    }
    MyInteger& operator= (MyInteger& inte)
    {
        if(m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
        
        this->m_Age = new int (*inte.m_Age);
        this->m_Num=inte.m_Num;
        return *this;
    }
private:
    int m_Num;
    int* m_Age;
};

MyInteger::MyInteger()
{
    m_Num=0;
    m_Age=NULL;
}

MyInteger::~MyInteger()
{
    if(m_Age!=NULL)
    {
        delete this->m_Age;
        this->m_Age=NULL;
    }
}

MyInteger::MyInteger(int age)
{
    m_Age=new int (age);
}

ostream& operator<< (ostream& cout, MyInteger inte)
{
    cout<<"编号："<<inte.m_Num<<"年龄:"<<*(inte.m_Age);
    return cout;
}

void test01()
{
    MyInteger myint(18);
    MyInteger myint2=myint;
    cout<<myint++<<endl;
    cout<<++myint2<<endl;

    return;     //堆区内存重复释放 程序崩溃
}

int main()
{
    test01();
    return 0;
}