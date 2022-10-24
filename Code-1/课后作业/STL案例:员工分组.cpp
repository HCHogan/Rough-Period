#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
using namespace std;
class Person{
public:
    string Name;
    int Salary;
};

void createPerson(vector<Person>&v)
{
    string NameSeed = "ABCDEFGHIJ";
    for(int i=0;i<10;i++)
    {
        Person p;
        p.Name="员工";
        p.Salary=rand()%10000+10000;
        p.Name+=NameSeed[i];
        v.push_back(p);
    }
}

void sortPerson(vector<Person>&v,multimap<int,Person>&m)
{
    int num;
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        num=rand()%3;
        m.insert(make_pair(num,*it));
    }
}

void printMap(multimap<int,Person>m)
{
    for(map<int,Person>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<"  "<<it->second.Name<<"  "<<it->second.Salary<<endl;
    }
}

int main(){
    srand((unsigned)time(NULL));
    multimap<int,Person>m;
    vector<Person>v;
    createPerson(v);
    sortPerson(v,m);
    //printMap(m);
    cout<<"策划部门:"<<endl;
    int count=m.count(0);
    multimap<int,Person>::iterator pos=m.find(0);
    for(int i=0;pos!=m.end()&&i<count;i++,pos++)
    {
        cout<<pos->first<<" "<<pos->second.Name<<" "<<pos->second.Salary<<endl;
    }
    cout<<"美术部门:"<<endl;
    count=m.count(1);
    pos=m.find(1);
    for(int i=0;pos!=m.end()&&i<count;i++,pos++)
    {
        cout<<pos->first<<" "<<pos->second.Name<<" "<<pos->second.Salary<<endl;
    }
    cout<<"研发部门:"<<endl;
    count=m.count(2);
    pos=m.find(2);
    for(int i=0;pos!=m.end()&&i<count;i++,pos++)
    {
        cout<<pos->first<<" "<<pos->second.Name<<" "<<pos->second.Salary<<endl;
    }
}