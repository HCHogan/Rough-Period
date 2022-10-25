#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int q[N],son[N][26],id[N],cnt[N],ne[N];
int n;
int idx;
char* str;
void TRIE_insert(const char* str,int k)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
    id[k]=p;
}
void build()
{
    int hh=0,tt=0;
    for(int i=0;i<26;i++)
    {
        if(son[0][i]) q[tt++]=son[0][i];
    }
    while(hh<tt)
    {
        int top=q[hh++];
        for(int i=0;i<26;i++)
        {
            int& p=son[top][i];
            if(!p) p=son[ne[top]][i];
            else
            {
                ne[p]=son[ne[top]][i];
                q[tt++]=p;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        TRIE_insert(str,i);
    }
    build();
    for(int i=idx;i>=1;i++) cnt[ne[id[i]]]+=cnt[id[i]];
    for(int i=1;i<=idx;i++) cout<<cnt[id[i]]<<endl;
    return 0;
}