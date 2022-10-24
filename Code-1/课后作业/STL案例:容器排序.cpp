#include<iostream>
using namespace std;
#include<list>
#include<string>
class Person{
public:
    string Name;
    int Age;
    int Height;
    Person(string name,int age,int height)
    {
        Name=name;
        Age=age;
        Height=height;
    }
};

bool myCompare(Person &p1,Person &p2){
    if(p1.Age==p2.Age)
    {
        return p1.Height>p2.Height;
    }
    else
    {
        return p1.Age>p2.Age;
    }
}

void printList(const list<Person>&l)
{
    for(list<Person>::const_iterator it=l.begin();it!=l.end();it++)
    {
        cout<<it->Name<<"  "<<it->Age<<"  "<<it->Height<<endl;
    }
}


int main(){
    list<Person>l;
    Person p1("m1",18,160);
    Person p2("m2",17,165);
    Person p3("m3",16,170);
    Person p4("m4",16,166);
    Person p5("m5",16,180);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.sort(myCompare);
    printList(l);
}