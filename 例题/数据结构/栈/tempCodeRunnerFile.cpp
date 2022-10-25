#include<iostream>
using namespace std;
const int N = 10001;
int queue[N], tail=0,head=0;
void push(int elem)
{
	if((tail+1)%N!=head%N)
	{
		queue[tail]=elem;
		tail=(tail+1)%N;
	}
	else cout<<"G了!"<<endl;
}
int pop()
{
	if(head!=tail)
	{
		int ret=queue[head];
		head=(head+1)%N;
		return queue[head];
	}
	return -1;
}
int back()
{
	int i=(tail-1+N)%N;
	return queue[i];
}
int front()
{
	return queue[head];
}
bool empty()
{
	return (tail-1)%N==head%N;
}
int size()
{
	if(head!=tail) return (tail-head+N)%N;
}
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