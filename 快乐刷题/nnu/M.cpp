#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;

int n,a[i];
bool book[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<=1e6;j++)
    {
        for(int i=1;i<=n;i++)
        {
           int t=j+a[i];
           if(!book[t])
           {
                book[t]=1
           }
        }
    }
}