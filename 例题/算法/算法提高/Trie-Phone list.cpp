#include<iostream>
#include<cstring>
//1,看有么有开新节点
//2，现有的 book是否为true
using namespace std;
const int N=10010;
int son[N][26];
int idx,T;
bool flag=0;
bool book[N];
char str[15];
bool insert(const char *str)
{
    int p=0;
    bool matched=false;
    bool have_new_node=false;
    
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'0';
        if(!son[u][p])
        {
            son[u][p]=++idx;
            have_new_node=1;
        }
        p=son[u][p];
        if(book[p]) matched=1;
    }

    book[p]=1;
    return !matched&&have_new_node;
}
int main()
{
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>str;
            insert(str);
        }
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>str;
            if(insert(str)) flag=1;
        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl; 
    }
    return 0;
}