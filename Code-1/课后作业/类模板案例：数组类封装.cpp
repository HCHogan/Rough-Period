#include<iostream>
#include<string>
using namespace std;
class Person{
    public:
        string m_name;
        int m_age;
        Person(){};
        Person(string name,int age){
            m_name=name;
            m_age=age;
        }
};

template<class T>
class Array{
public:
    Array(int capacity){//传入容量的构造函数
        Capacity=capacity;
        Size=0;
        arr=new T [capacity];
    }
    Array(const Array &p){//利用深拷贝的拷贝构造函数
        
        Capacity=p.Capacity;
        Size=p.Size;
        this->arr=new T [Capacity];
        for(int i=0;i<Size;i++)
        {
            arr[i]=p.arr[i];
        }
    }
    ~Array(){
        if(arr!=NULL)
        {
            delete[] arr;
            arr=NULL;
            Size=0;
            Capacity=0;
        }
    }
    Array& operator=(const Array& p)//允许arr1=arr2的操作
    {
        if(arr!=NULL)
        {
            delete[] arr;
            arr=NULL;
            this->Capacity=0;
            this->Size=0;
        }
        this->Capacity=p.Capacity;
        Size=p.Size;
        this->arr=new T [Capacity];
        for(int i=0;i<Size;i++)
        {
            arr[i]=p.arr[i];
        }
        return *this;
    }
    int getCap()
    {
        return this->Capacity;
    }
    int getSize()
    {
        return this->Size;
    }
    T& operator[](int index)//以类名代替数组名以后，真正的数组收地址是类中的arr，而通过重载【】而用类名访问数组
    {
        return this->arr[index];
    }
    void printIntArr(Array<int>&p){
        for(int i=0;i<p.getSize();i++)
        {
            cout<<arr[i]<<endl;
        }
    };
    void push(const T & a){//v.push
        if(Capacity==Size){
            return;
        }
        arr[Size]=a;
        Size++;
    }
    void pop(){
        if(Size==0){
            return;
        }
        Size--;
    }
private:
    int Size;
    int Capacity;
    T*arr;
};
void PrintPersonArr(Array<Person>& p){
        for(int i=0;i<p.getSize();i++)
        {
            cout<<p[i].m_name<<"  "<<p[i].m_age<<endl;
        }
    };

int main(){
    Array<Person>fuck(5);
    Person p1("sb",18);
    Person p2("sd",18);
    Person p3("sp",18);
    Person p4("sg",18);
    Person p5("lhr",18);
    fuck.push(p1);
    fuck.push(p2);
    fuck.push(p3);
    fuck.push(p4);
    fuck.pop();
    fuck.push(p5);
    PrintPersonArr(fuck);//如果函数声明在类内，需要Array.来实现
}