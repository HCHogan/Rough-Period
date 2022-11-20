#include<iostream>
using namespace std;
int ans=0,num,k;
int path[1000];
void dfs(int x,int n)
{
    if(n==k&&x>=path[n-1])
    {
        path[n]=x;
        ans++;
        return;
    }
    else{
        for(int temp=path[n-1];temp<x;temp++)
        {
            path[n]=temp;
            dfs(x-temp,n+1);
        }
    }
}

int main()
{
    path[0]=1;
    cin>>num>>k;
    dfs(num,1);
    cout<<ans;
}