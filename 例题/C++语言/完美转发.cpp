#include<iostream>
using namespace std;

void func1(int& a)
{
    cout<<"func1接受到的值是左值"<<endl;
}

void func1(int&& a)
{
    cout<<"func1接受到的值是右值🙅"<<endl;
}
/*
template<typename T>
void func2(T& a)
{
    func1(a);
}

template<typename T>
void func2(T&& a)
{
    func1(move(a));
}
*/
    //c++11中 T&& 可以接受左值和右值
    //std::forward<T>(ii)用于保留左值和右值的信息然后转发 
    //完美转发这样写
    //！！只有模版T&&才能接受左值和右值 int&&之类的不行

template<typename TT>
void func2(TT&& ii)
{
    func1(forward<TT>(ii));
}

int main()
{
    int a=1;
    func2(1);
    func2(a);
    return 0;
}