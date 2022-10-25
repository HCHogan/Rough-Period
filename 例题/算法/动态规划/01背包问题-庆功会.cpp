#include<iostream>
using namespace std;
const int N=10001;
int f[N],n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int space,value,sum;
        cin>>space>>value>>sum;
        for(int j=m;j>=1;j++)
        {
            for(int k=0;k<=sum;k++)
            {
                if(j+k*space) break;
                f[j]=max(f[j],value+f[j-space]);
            }
        }
    }
    printf("%d\n",f[n]);
    return 0;
}