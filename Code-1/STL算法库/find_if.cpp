#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>
class Greater{
    public:
    bool operator()(int a)
    {
        return a>5;
    }
};
class Person{
    public:
        int Age;
        string Name;
        Person(int age,string name)
        {
            Age=age;
            Name=name;
        }
};

class older{
    public:
    bool operator()(const Person &p)
    {
        return p.Age>20;
    }
};

int main(){
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it=find_if(v.begin(),v.end(),Greater());
    cout<<*it;
//-------------------------------------------------
    vector<Person>vp;
    Person p1(18,"sb");
    Person p2(30,"sp");
    Person p3(40,"sd");
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vector<Person>::iterator its=find_if(vp.begin(),vp.end(),older());
    cout<<its->Name;
}