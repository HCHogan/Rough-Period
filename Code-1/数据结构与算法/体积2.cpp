#include<iostream>
using namespace std;
int n,ans=0;
const int N=25,M=1010;
int path[N];
bool h[M];

void work(int s)
{
    for(int i=0;i< 1<<n ;i++)
    {
        s=0;
        for(int j=0;j<n;j++)
        {
            if(i>>j &1) s+=path[j];
        }
        h[s]=true;
    }
    //h[s]=true;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>path[i];
    }
    work(0);
    for(int i=1;i<=M;i++)
    {
        if(h[i]) ans++;
    }
    cout<<ans;
}