#include<iostream>
using namespace std;
const int N=25;
int n,s,sum=0;
int path[N];
int total=0;

void work(int u,int s,int pre)
{
    if(s==0)
    {
        total++;
        cout<<path[1];
        for(int i=2;i<=u-1;i++)
        {
            cout<<"+"<<path[i];
        }
        cout<<endl;
        return;
    }
    for(int i=pre;i<=s;i++)
    {
        s-=i;
        path[u]=i;
        work(u+1,s,i);
        s+=i;
    }
}

int main()
{
    cin>>n;
    work(1,n,1);
    cout<<"total="<<total;
}