#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f,MOD=1e9+7;

int v,w,n,m;
int f[N],c[N];

int main()
{
    cin>>n>>m;
    while(n--)
    {
        cin>>v>>w;
        for(int j=m;j>=v;j--)
        {
            if(f[j]<f[j-v]+w)
            {
                f[j]=f[j-v]+w;
                c[j]=c[j-v];
            }
            else if(f[j]==f[j-v]+w)
            {
                c[j]=(c[j]+c[j-v])%MOD;
            }
        }
    }
    cout<<c[m]<<endl;
    return 0;
}