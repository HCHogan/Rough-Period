#include<iostream>
using namespace std;
int n;
const int N=15;
int a[N];
bool book[N];

void dfs(int u)
{
    if(u>n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!book[i]){
        book[i]=true;
        a[u]=i;
        dfs(u+1);
        book[i]=false;
        }
    }
}

int main()
{
    cin>>n;
    dfs(1);
    return 0;
}