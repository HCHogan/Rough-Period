#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int N=10010;
int son[N][26],cnt[N],idx=0;
char str[N];
int insert(const char* str)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[u][p]) son[u][p]=++idx;
        p=son[u][p];
    }
    cnt[p]++;
}
int query(const char* str)
{
    int p=0,res=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[u][p]) return res;
        res+=cnt[p];
        p=son[u][p];
    }
    return res;
}
int main()
{
    cin>>n>>m;
    while(n--)
    {
        cin>>str;
        insert(str);
    }
    while(m--)
    {
        cin>>str;
        cout<<query(str)<<endl;
    }
}