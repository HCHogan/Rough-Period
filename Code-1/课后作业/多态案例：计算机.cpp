#include<iostream>
using namespace std;
class abstractComputer{
    public:
        int num1;
        int num2;
        virtual int calculate(){
            return 0;
        }
};

class add:public abstractComputer{
    public:
    int calculate(){
        return num1+num2;
    }
};

class sub:public abstractComputer{
public:
    int calculate(){
        return num1-num2;
    }
};

class mul:public abstractComputer{
public:
    int calculate(){
        return num1*num2;
    }
};

void test01(){
    abstractComputer * abc=new add;
    abc->num1=10;
    abc->num2=10;
    cout<<"mun1 + num2 ="<<abc->calculate()<<endl;
    delete abc;
    abc=new sub;
    abc->num1=10;
    abc->num2=10;
    cout<<"num1 - num2 ="<<abc->calculate()<<endl;
    delete abc;
    abc=new mul;
    abc->num1=10;
    abc->num2=10;
    cout<<"num1 * num2 ="<<abc->calculate()<<endl;
}

int main(){
    abstractComputer c;
    test01();
}