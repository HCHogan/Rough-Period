#include<iostream>
using namespace std;
int stack[101]; 
int top=0; 

void push(int elem) //��ջ 
{
	if(top< 100)
	{
		stack[++top] = elem;
	}
}
void pop() //����һ����ɾ���������Ǹ��� 
{
	if (top>0) top--;
}

int getTop() //ջ��Ԫ�� 
{
	return stack[top];
}

void clear() //���ջ 
{
	top = 0;
}

int main()
{
	push(3);
	push(4);
	push(5);
	cout<<getTop()<<endl;   //5
	pop();
	pop();
	cout<<getTop()<<endl;    //3
	
	return 0;
}
