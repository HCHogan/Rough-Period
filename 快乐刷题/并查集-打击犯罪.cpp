#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=10010;
int father[N],sum[N];
int n,m,cnt;
vector<int> v[N];

int find(int x)
{
    if(x!=father[x]) father[x]=find(father[x]);
    return x;
}

int merge(int x,int y)
{
    sum[x]+=sum[y];
    father[y]=x;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int cnt;
        cin>>cnt;
        while(cnt--)
        {
            int x;
            v[i].push_back(x);
        }
    }

    for(int i=1;i<=n;i++)
    {
        father[i]=i;
        sum[i]=1;
    }

    for(int i=n;i>=1;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j]>i)
            {
                int fa=find(i),fb=find(v[i][j]);
                if(fa!=fb) merge(fa,fb);
                else continue;
                
                if(sum[i]>n/2)
                {
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
    }
}