#include<iostream>
using namespace std;
class Animal
{
public:
    virtual void speak()        //虚函数的实现无意义 =0 变成纯虚函数
    {
        cout<<"动物在说话"<<endl;
    }
};

class Dog :public Animal
{
public:
    void speak()
    {
        cout<<"小狗在说话"<<endl;
    }
};

class Cat :public Animal
{
public:
    void speak()
    {
        cout<<"小猫在说话"<<endl;
    }
};

//地址早绑定 在编译阶段确定函数地址
void doSpeak(Animal &animal)
{
    animal.speak();
}
//动态多态条件 1，继承关系 2，子类重写父类虚函数(重写的概念：函数返回值 函数名 参数列表 完全一致)
//动态多态使用
//夫类的指针或者引用指向子类对象

void test01()
{
    Cat cat;
    Dog dog;
    Animal animal;
    doSpeak(cat);       //想让猫说话
    doSpeak(dog);
    doSpeak(animal);
}

int main()
{
    test01();
    return 0;
}