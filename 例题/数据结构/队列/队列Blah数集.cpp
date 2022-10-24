#include<iostream>
#include<algorithm>
using namespace std;
int a,n,q[1000005];
void calc(int a, int n)
{
    q[1]=a;
    int two=1,three=1,rear=2;
    while(rear<=n)
    {
        long long t1=q[two]*2+1;
        long long t2=q[three]*3+1;
        long long t=min(t1, t2);
        if(t1<t2) two++;
        else three++;
        if(t<=q[rear-1]) continue;
        q[rear++]=t;
    }
}
int main()
{
    calc(1,100);
    for(int i =1;i<=100;i++) cout<<q[i]<<" ";
    return 0;
}