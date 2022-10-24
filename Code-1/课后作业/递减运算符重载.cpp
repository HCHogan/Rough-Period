#include<iostream>
using namespace std;
class myInt{
    public:
        myInt(){
            num=0;
        }
        //前置递减
        myInt& operator--(){
            num--;
            return *this;
        }
        //后置递减
        int operator--(int){
            int temp=num;
            num--;
            return temp;
        }
    friend ostream& operator<<(ostream& cout,myInt myint);
    
    private:
        int num;
};
ostream& operator<<(ostream& cout,myInt myint){
    cout<<myint.num;
    return cout;
}

int main(){
    myInt sd;
    cout<<sd--;
    cout<<sd;
}