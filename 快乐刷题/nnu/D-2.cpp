#include<iostream>
using namespace std;
const int N=2e5+10,INF=0x3f3f3f3f;

int tr[N],n,m,x;
long long t;
int cnt;
int askans[N];

int lowbit(int x)
{
    return x&-x;
}

void update(int x,int t)
{
    while(x<=n)
    {
        tr[x]+=t;
        x+=lowbit(x);
    }
}

int ask(int x)
{
    if(x==0) return 0;
    int t=0;
    while(x>=1)
    {
        t+=tr[x];
        x-=lowbit(x);
    }
    return t;
}
 
int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        update(i,x);
    }

    for(int i=0;i<=n;i++)
    {
        askans[i]=ask(i);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(askans[j]-askans[i]<t) cnt++;
        }
    }
    cout<<cnt<<endl;
}