#include<iostream>
using namespace std;
class makeDrink{
    public:
        virtual void boil()=0;
        virtual void brew()=0;
        virtual void pour()=0;
        virtual void add()=0;
        void doWork(){
            add();
            boil();
            brew();
            pour();
        }
};

class Coffee:public makeDrink{
    virtual void boil(){
        cout<<"煮开水"<<endl;
    }
    virtual void brew(){
        cout<<"冲泡咖啡"<<endl;
    }
    virtual void pour(){
        cout<<"倒入咖啡杯"<<endl;
    }
    virtual void add(){
        cout<<"加入糖和牛奶"<<endl;
    }
};

class Tea:public makeDrink{
    public:
        virtual void boil(){
        cout<<"煮农夫山泉"<<endl;
    }
    virtual void brew(){
        cout<<"冲泡茶叶"<<endl;
    }
    virtual void pour(){
        cout<<"倒入茶壶"<<endl;
    }
    virtual void add(){
        cout<<"加入柠檬片"<<endl;
    }
};

void makeIt(makeDrink * d){
    d->doWork();
    delete d;
}
void test01(){
    makeIt(new Coffee);
}

int main(){
    test01();
}