#include<iostream>
using namespace std;
const int N=10000;
int a[N],b[N];
int n;
bool book[N],book2[N];
bool flag=true;
void dfs(int u)
{
    if(u>=n+1)
    {
        for(int i=1;i<=n;i++) cout<<b[i]<<" ";
        exit(0);
    }
    for(int i=0;;i++)
    {
        for(int j=u;j<=n;j++)
        {
            if(i==a[j])
            {
                // if(i==n+100)
                // {
                //     flag=false;
                //     cout<<"-1"<<endl;
                //     exit(0);
                // }
                i++;
                continue;
            }
        }
        // if(book2[i]==true)
        // {
        //     i++;
        //     if(i==n+100)
        //     {
        //         cout<<"-1"<<endl;
        //         exit(0);
        //     }
        //     continue;
        // }
        if(book[i]==false&&i!=a[u])
        {
            b[u]=i;
            //book2[a[u]]=false;
            book[i]=true;
            dfs(u+1);
        }
        // cout<<"-1"<<endl;
        // exit(0);
    }
}

int main()
{
    a[0]=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];//有序递增数组
        book2[a[i]]=true;
    }
    dfs(1);
}