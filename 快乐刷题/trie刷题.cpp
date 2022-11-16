#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int son[N][26],n,m,idx,cnt[N];
char str[N];

void insert(const char* str)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}

int ask(const char* str)
{
    int res=0,p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u]) return res;
        p=son[p][u];
        res+=cnt[p];
    }
    return res;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        insert(str);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>str;
        cout<<ask(str)<<endl;
    }
    return 0;
}