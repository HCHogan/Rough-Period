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
        bool operator==(const Person &p)
        {
            if(p.Age==Age)
            {
                return true;
            }
            else{
                return false;
            }
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
    int x=count(v.begin(),v.end(),9);
    cout<<x<<endl;
//-----------------------------------------
    vector<Person>vp;
    Person p1(18,"sb");
    Person p2(30,"sp");
    Person p3(30,"sd");
    Person p4(30,"hehe");
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    x=count(vp.begin(),vp.end(),p4);
    cout<<x;
}