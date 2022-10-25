#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int N=10001;
int n,t;
int f[N];
int main()
{
    cin>>t>>n;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)
    {
        int time,value;
        cin>>time>>value;
        for(int j=t;j>=time;j--)
            f[j]=max(f[j],value+f[j-time]);
    }
    cout<<f[t];
}