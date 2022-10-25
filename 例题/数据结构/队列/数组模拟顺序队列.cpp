#include<iostream>
using namespace std;
const int N=10000;
int queue[10001];
int head=0,tail=0;//队首指针，队尾指针
void push(int elem);//在队尾插入元素
int pop();//弹出队尾元素
bool empty();//空1不空0
int size();//获取队列元素个数
int front();//获取队首元素
int back();//获取队尾元素
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    cout<<size()<<endl;
    cout<<empty()<<endl;
    cout<<front()<<endl;
    cout<<back()<<endl;
    return 0;
}
void push(int elem)
{
    if(tail<N) queue[tail++]=elem;
}
int pop()
{
    if(head!=tail) return queue[head++];
}
bool empty()
{
    return head==tail;
}
int size()
{
    return tail-head;
}
int front()
{
    if(head!=tail) return queue[head];
}
int back()
{
    if(head!=tail)
    {
        int i=tail-1;
        return queue[i];
    }
}