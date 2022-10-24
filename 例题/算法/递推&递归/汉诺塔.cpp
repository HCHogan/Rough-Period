#include<iostream>
#include<stack>
using namespace std;
int n,cnt=0;
stack<int> a,b,c;
void moveTower(int n,char from,char to,char buffer)
{
    if(!n) return;
    moveTower(n-1,from,buffer,to);
    printf("%d :from %c -->%c\n",++cnt,from ,to);
    moveTower(n-1,buffer,to,from);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) a.push(i);
    moveTower(n,'a','c','b');
    return 0;
}