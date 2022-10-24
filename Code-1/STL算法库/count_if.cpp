#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
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

class great{
    public:
    bool operator()(int a)
    {
        return a>5;
    }
};

class Great{
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
    v.push_back(9);
    v.push_back(9);
    v.push_back(9);
    int x=count_if(v.begin(),v.end(),great());
    cout<<x<<endl;
//-----------------------------------------
    vector<Person>vp;
    Person p1(18,"sb");
    Person p2(30,"sp");
    Person p3(30,"sd");
    Person p4(30,"he");
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    x=count_if(vp.begin(),vp.end(),Great());
    cout<<x;
}