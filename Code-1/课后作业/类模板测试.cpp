#include<iostream>
#include<string>
using namespace std;
template<class nameType,class ageType>
class Person{
public:
    nameType m_name;
    ageType m_age;
    Person(nameType name,ageType age){
        m_name=name;
        m_age=age;
    }
    void show(){
        cout<<m_name<<endl;
        cout<<m_age<<endl;
    }
};

int main (){
    Person<string,int> p1 ("sb",19);
    p1.show();
}