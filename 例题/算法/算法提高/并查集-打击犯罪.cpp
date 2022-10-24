#include<iostream>
#include<vector>
using namespace std;
vector<int> v[N];
const int N=10010;
int father[N],sum[N];
int n,m,cnt;

int find(int x)
{
    if(x!=father[x]) father[x]=find(father[x]);
    return x;
}

int merge(int x,int y)
{
    father[y]=x;
    sum[x]+=sum[y];
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
            cin>>x;
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
            if(find(i)!=find(v[i][j])) merge(find(i),find(v[i][j]));
            else continue;

            if(sum[i]>n/2)
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
}