#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int a,b,n,cnt=1;
int dfsans[N],tempans[N],idx;
int da,db;


void calc(int cnt,int dfsans[])
{
    for(int i=1;i<=cnt;i++)
        tempans[idx]+=dfsans[i]*pow(10.0,(double)(cnt-i));
    idx++;
}

void dfs(int u,int left)
{
    if(u>cnt&&left==0)
    {
        calc(cnt,dfsans);
        return;
    }
    else if(u>cnt) return;
    if(left>0)
    {
        dfsans[u]=a;
        dfs(u+1,left-1);
    }
     
    dfsans[u]=b;
    dfs(u+1,left);
}

int main()
{
    cin>>n>>a>>b;
    int x=n;
    db=max(a,b);
    da=min(a,b);
    bool flag=0;
    for(int i=1;i<=9;i++)
    {
        if(x/10!=0) cnt++;
        x/=10;
    }
    cout<<cnt<<endl;
    int init=9-cnt+2;
    if(cnt%2==0)
    {
        dfs(1,cnt/2);
        cout<<idx<<endl;
        for(int i=0;i<=idx;i++) cout<<tempans[i]<<" ";
        cout<<endl;
        int* p=lower_bound(tempans,tempans+idx+1,n);
        if(p==tempans+idx+1)
        {
            for(int i=1;i<=(cnt/2)+1;i++)
            {
                cout<<da;
            }
            for(int i=(cnt/2)+2;i<=cnt+2;i++)
            {
                cout<<db;
            }
            cout<<endl;
        }
        else cout<<*p<<endl;
    }
    else
    {
        for(int i=1;i<=(cnt+1)/2;i++)
        {
            cout<<da;
        }
        for(int i=(cnt+1)/2+1;i<=cnt+1;i++)
        {
            cout<<db;
        }
        cout<<endl;
    }
}