#include<iostream>
using namespace std;
const int N = 101;
int q[N], front =0, back=0;
void push(int elem)
{
	if(back<N) q[++back]=elem;
}
void pop()
{
	if(front!=back) front ++;
}
bool isEmpty()
{
	return back == front;
}
int getLen()
{
	return back - front;
}
int getBack()
{
	if(front!=back) return q[back];
}
int getFront()
{
	if(front!=back) return q[front+1];
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
	cout<<getLen()<<endl;  //5
	cout<<isEmpty()<<endl;  //0
	cout<<getFront()<<endl; //2
	cout<<getBack()<<endl; //6
	return 0;
}
