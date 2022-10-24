#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int T,idx,res;
char str[N];
int son[N][26],cnt[N],ne[N];
void trie_insert(const char* str)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u]) son[p][u]==++idx;
        p=son[p][u];
    }
    cnt[p]++;
}

void build()
{
    int p=0;
    int tt=0,hh=0;
    int q[N];
    for(int i=0;i<26;i++)
    {
        if(son[0][i]) q[tt++]=son[0][i];
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
}

int AC_match(const char* str)
{
    int res=0;
    for(int i=0,j=0;i<26;i++)
    {
        int u=str[i]-'a';
        j=son[j][u];
        int p=j;
        while(p)
        {
            res+=cnt[p];
            cnt[p]=0;
            p=ne[p];
        }
    }
    return res;
}
int main()
{
    cin>>T;
    while(T--)
    {
        memset(str,0,sizeof str);
        cin>>str;
        trie_insert(str);
        build();
        res=0;
        cin>>str;
        cout<<AC_match(str)<<endl;
    }
    return 0;
}