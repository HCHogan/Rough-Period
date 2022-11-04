#include<iostream>
#include<list>
#include<deque>
using namespace std;
int get_int_target()
{
    return rand();
}

int main()
{
    list<int> lst;
    deque<int> deq;
    while(1)
    {
    int timestart=clock();
    cout<<lst.max_size()<<endl;
    for(int i=1;i<=10000000;i++)
    {
        deq.push_back(get_int_target());
    }
    cout<<(int)clock()-timestart<<endl;
    }
    return 0;
}
