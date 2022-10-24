#include<iostream>
using namespace std;
const int N=10010;

int n,m;
int f[N],g[N],q[N];

int main()
{
    cin>>n>>m;

    while(n--)
    {
        int v,w,s;
        for(int r=0;r<v;r++)
        {
            int hh=0,tt=0;
            for(int j=r;j<=m;j+=v)
            {
                if(hh<tt&&q[hh]<j-s*v) hh++;
                //头不在窗口中 头出队
                if(hh<tt) f[j]=max(g[j],g[j-q[hh]]+(j-q[hh])/v*w);
                //使用dp更新f
                while(hh<tt&&g[j]>=g[j-q[tt]]+(j-q[tt])/v*w) tt--;
                //当前值比队尾值更有价值，队尾出队
                q[tt++]=j;      //当前下标入队
            }
        }
    }

    cout<<f[m]<<endl;

    return 0;
}