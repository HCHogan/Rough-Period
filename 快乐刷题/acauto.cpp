#include<iostream>
#include<queue>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

char str[N];
int son[N][26],idx,n,m,cnt[N],ne[N];

void build()
{
    queue<int> q;
    for(int i=0;i<26;i++)
    {
        if(son[0][i]) q.push(son[0][i]);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++)
        {
            if(son[u][i])
            {
                ne[son[u][i]]=son[ne[u]][i];        //回溯边
                q.push(son[u][i]);
            }
            else
            {
                son[u][i]=son[ne[u]][i];        //转移边
            }
        }
    }
}

void insert(const char* str)
{
    int p=0;
    for(int i=1;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}

int query(char* str)
{
    int p=0,res=0;
    for(int i=1;str[i];i++)
    {
        int u=str[i]-'a';
        p=son[p][u];
        for(int j=p;~cnt[j];j=ne[j])
        {
            res+=cnt[j];
            cnt[j]=-1;
        }
    }
    return res;
}