#include<iostream>
using namespace std;
const int N = 10001;
char queue[N];
int tail=0,head=0;
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
	freopen("宴请宾客.in","r",stdin);
    freopen("宴请宾客.out","w",stdout);
    char ch;
    while(cin>>ch)
    {
        if(ch=='B')
        {
            int i;
            cin>>i;
            push(i);
        }
        else
        {
            if(head!=tail)
            {
                cout<<front()<<endl;
                pop();
            }
            else cout<<"None"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}