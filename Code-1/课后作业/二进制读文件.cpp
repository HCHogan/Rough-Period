#include<iostream>
using namespace std;
#include<fstream>
class Person{
    public:
        char name[64];
        int age;
};
int main(){
    Person p;
    ifstream ifs;
    ifs.open("person.txt",ios::in | ios::binary);
    if(!ifs.is_open()) {
        cout<<"文件打开失败"<<endl;
    }
    ifs.read((char *)&p,sizeof(p));
    cout<<"姓名 "<<p.name<<" 年龄 "<<p.age<<endl;
    ifs.close();
}