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
	int num, cnt =0;
	cin>>num;
	while(num)
	{
		push(num%2);
		num/=2;
		cnt++;
	}
	for(int i=1;i<=cnt;i++)
	{
		cout<<getTop();
		pop();
	}
	return 0;
}
