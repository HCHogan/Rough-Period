#include<iostream>
using namespace std;
const int N=8;
int a[N];
int head=0,tail=0;

void pop();
void push(int elem);
int front();
int back();
int size();

int main()
{
    pop();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    cout<<tail<<endl;
    push(8);
    cout<<head<<"  "<<tail<<endl;
    cout<<size()<<endl;
    pop();
    pop();
    pop();
    //cout<<a[head]<<endl;
    push(9);
    push(10);
    push(11);
    cout<<tail<<endl;
    cout<<size()<<endl;
    for(int i=0;i<=size();i++)
    {
        if(i==tail) continue;
        cout<<a[i]<<" ";
    }
}

void pop()
{
    if(head==tail) cout<<"队列为空"<<endl;
    else {head=(head+1)%N;}
}

void push(int elem)
{
    if((tail+1)%N==head) cout<<"队列已满"<<endl;
    else {a[tail++]=elem;tail=tail%N;}
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
    return (tail-head+N)%N;
}