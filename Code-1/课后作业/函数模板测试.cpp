#include<iostream>
#include<string>
using namespace std;
template<class T>//T可以为任意标识符，一般为大写字母，习惯用T
void compare(T &a, T &b){
    if(a==b){
        cout<<"a==b"<<endl;
    }
    else{
        cout<<"a!=b"<<endl;
    }
}

class Person{
public:
    string m_name;
    int m_age;
    Person(string name,int age){
        m_age=age;
        m_name=name;
    }
};

template<>//重载格式
void compare(Person &a,Person &b){
    if(a.m_age==b.m_age){
        cout<<"a==b"<<endl;
    }
    else{
        cout<<"卢本伟牛逼"<<endl;
    }
}

int main(){
    int a=10,b=10;
    compare (a,b);
    Person p1("sb",18);
    Person p2("sd",19);
    compare(p1,p2);//模板不是万能的
}