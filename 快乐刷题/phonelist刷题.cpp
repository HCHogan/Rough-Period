#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int T,n;
int son[N][26],idx;
char str[N];
bool book[N];

int insert(const char* str)
{
    int p=0;
    bool created_new_node=0,matched=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u])
        {
            son[p][u]=++idx;
            created_new_node=1;
        }
        p=son[p][u];
        if(book[p]) matched=1;
    }
    book[p]=1;
    return !matched&&created_new_node;
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>str;
        insert(str);
    }
}