#include<iostream>
using namespace std;
const int N=25,M=1010;
int n,ans=0;
int a[N];
bool h[M];

void dfs(int u,int s)
{
    if(u>n)
    {
        h[s]=true;
        return;
    }
    dfs(u+1,s);//没选择这个数的情况
    dfs(u+1,s+a[u]);//选择了这个数的情况
    //无论选或不选，层数一定++，这样才能保证算法有穷。而不选的则这一层置空即可
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0);
    for(int i=1;i<=M;i++)
    {
        if(h[i]) ans++;
    }
    cout<<ans;
}