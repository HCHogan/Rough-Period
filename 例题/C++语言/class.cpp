#include<iostream>
using namespace std;
class Person
{
public:
    Person()
    {
        cout<<"nsml"<<endl;
    }
    ~Person()
    {
        cout<<"si"<<endl;
    }
    int age;
    Person(const Person& p)
    {
        cout<<"copy"<<endl;
        age=p.age;
    }
};
void hehe()
{
    Person p1;
    p1.age=18;
    Person p2=p1;
    cout<<"p2age="<<p2.age<<endl;
}
int main()
{
    hehe();
    return 0;
}