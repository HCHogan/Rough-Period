#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
int n;
int g[N][N],minw[N],book[N];     //minw?

int prim()
{
    memset(minw,0x3f,sizeof minw);
    memset(book,0,sizeof book);
    minw[1]=0;
    for(int i=1;i<=n;i++)
    {
        int k=0;
        for(int j=1;j<=n;j++)
        {
            if(!book[j]&&minw[k]>minw[j]) k=j;
        }
        book[k]=1;
        for(int j=1;j<=n;j++)
        {
            if(!book[j]&&minw[j]>g[k][j]) minw[j]=g[k][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=minw[i];
    }
    return ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
        }
    }
    cout<<prim()<<endl;
}