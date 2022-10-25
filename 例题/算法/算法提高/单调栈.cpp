#include<iostream>
using namespace std;
const int N=10010;
int stk[N];
int top=0,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        while(top&&x>=stk[top]) top--;
        if(top) cout<<stk[top]<<" ";
        else puts("-1");
        stk[++top]=x;
    }
    return 0;
}