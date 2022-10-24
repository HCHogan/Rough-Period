#include<iostream>
using namespace std;
int stack[101]; 
int top=0; 

void push(int elem) //入栈 
{
	if(top< 100)
	{
		stack[++top] = elem;
	}
}
void pop() //弹出一个（删掉最上面那个） 
{
	if (top>0) top--;
}

int getTop() //栈顶元素 
{
	return stack[top];
}

void clear() //清空栈 
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
