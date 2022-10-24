#include<iostream>
using namespace std;
const int N=0x3f,M=N*N;
int h[N],to[M],ne[M],wei[M],idx=0;
int n,m;
int add(int a,int b,int c)
{
    wei[idx]=c;
    to[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;

}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;      //从a到b，wei=c
        cin>>a>>b>>c;
        add(a,b,c);
        //add(b,a,c);无向图
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i;
        for(int j=h[i];~j;j=ne[j])
            printf("%d %d  |  ",wei[j],to[j]);
        puts("");
    }
    return 0;
}