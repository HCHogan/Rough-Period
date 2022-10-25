#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
int idx=0,son[N][26],ne[N],cnt[N],q[N];
int tt=0,hh=0;
int res=0;
char str[N];
void insert(const char* str)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][i]) son[p][i]=++idx;
        p=son[p][i];
    }
    cnt[p]++;
}

void build()
{
    for(int i=0;i<26;i++)
    {
        if(son[0][i]) q[tt++]=son[0][i];
    }
    while(hh<tt)
    {
        int t=q[hh++];
        for(int i=0;i<26;i++)
        {
            int& p=son[t][i];
            if(!p) p=son[ne[t]][i];
            else
            {
                ne[p]=son[ne[t]][i];
                q[tt++]=p;
            }
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>str;
            insert(str);
        }
        cin>>str;
        build();
        int res=0; 
        for(int i=0,j=0;str[i];i++)
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
        cout<<res<<endl;
    }
}