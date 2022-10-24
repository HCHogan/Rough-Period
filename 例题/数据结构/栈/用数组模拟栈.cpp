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
	push(3);
	push(4);
	push(5);
	cout<<getTop()<<endl;   //5
	pop();
	pop();
	cout<<getTop()<<endl;    //3
	
	return 0;
}
