#include<iostream>
#include<list>
using namespace std;
list<int> lst;
int main()
{
    lst.push_back(1);       //尾插法
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_front(0);
    list<int>::iterator it=lst.begin();
    for(it=lst.begin();it!=lst.end();it++) cout<<*it;
    lst.insert(it,88);
    lst.erase(it);      //实质上是链表 it存地址 erase了不动
}