#include<iostream>
#include<queue>
using namespace std;
queue<int> q1;
queue<int> q2;
int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++) q1.push(i);
    for(int i=1;i<=k;i++) q2.push(i);
    for(int i=1;i<=k;i++)
    {
        int a = q1.front();
        int b = q2.front();
        cout<<a<<" "<<b<<endl;
        q1.pop();
        q2.pop();
        q1.push(a);
        q2.push(b);
    }
}