#include<iostream>
using namespace std;
const int N=10001;
int f[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int space,value,sum;
        cin>>space>>value>>sum;
        if(sum==0)
        {
            for(int j=space;j<=m;j++) f[j]=max(f[j],f[j-space]+value);
        }
        else
        {
            for(int j=m;j>=space;j++)
            {
                for(int k=0;k<=sum;j++)
                {
                    if(j+k*space>m) break;
                    else
                    {
                        f[j]=max(f[j],f[j-k*space]+value);
                    }
                }
            }
        }
    }
    cout<<f[n];
}