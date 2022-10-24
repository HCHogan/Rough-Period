#include<iostream>
using namespace std;
int n,p,m,q,cnt=0,total_out=0;
bool f[300];
int main()
{
    cin>>n>>p>>m;
    memset(f,1,sizeof f);
    while(total_out<n)
    {
        int i;
        i=(i+1)%n;
        if(total_out==n) break;
        if(f[i])
        {
            if(cnt==m-1)
            {
                f[i]=0;
                cnt=0;
                total_out++;
                cout<<i+1<<" ";
            }
            else
            {
                cnt++;
            }
        }
    return 0;
    }
}