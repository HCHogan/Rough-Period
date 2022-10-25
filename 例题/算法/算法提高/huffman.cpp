#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=10001,INF=0x3f3f3f3f;
int n;
int main()
{
    while(cin>>n)
    {
        priority_queue<int,vector<int>,greater<int>> q;
        while(n--)
        {
            int x;
            cin>>x;
            q.push(x);
        }
        int res=0;
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            q.push(a+b);
            res+=a+b;
        }
        cout<<res<<endl;
    }
    return 0;
}