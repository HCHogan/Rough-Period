#include<iostream>
using namespace std;
class myInt{
public:
friend ostream& operator<<(ostream& cout,myInt myint);
//前置递增
myInt& operator++(){
    num++;
    return *this;
}
//后置递增
int operator++(int){
    int temp=num;
    num++;
    return temp;
}
myInt(){
    num=0;
}
private:
    int num;
};

ostream& operator<<(ostream& cout,myInt myint){
    cout<<myint.num;
    return cout;
}

int main(){
    myInt sd;
    cout<<sd++;
    cout<<sd;
}