#include<iostream>
using namespace std;
#include<fstream>
class Person{
    public:
        char name[64];
        int age;
};
int main(){
    ofstream ofs;
    ofs.open("person.txt",ios::out | ios::binary);
    Person p={"张三",18};
    ofs.write((const char *)&p,sizeof(p));
    ofs.close();
}