#include<iostream>
using namespace std;
int a[100];
int head=0,tail=0;
void pop();
void push(int elem);
int front();
int back();
int size();
int main()
{
    push(1);
    push(1);
    push(1);
    push(1);
    cout<<size()<<endl;
    pop();
    cout<<size()<<endl;
    for(int i=0;i<size();i++)
    {
        cout<<a[i]<<" ";
    }
}

void pop()
{
    if(head==tail) cout<<"队列为空"<<endl;
    else head++;
}

void push(int elem)
{
    a[tail++]=elem;
}

int front()
{
    return a[head];
}

int back()
{
    return a[tail-1];
}

int size()
{
    return tail-head;
}