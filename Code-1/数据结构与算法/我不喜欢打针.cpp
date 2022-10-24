#include<iostream>
using namespace std;
#include<queue>
queue<int> q;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    while(q.size()>=2)
    {
        cout<<q.front()<<" ";
        q.pop();
        int a=q.front();
        q.pop();
        q.push(a);
    }
    if(q.size()==1) cout<<q.front();
}