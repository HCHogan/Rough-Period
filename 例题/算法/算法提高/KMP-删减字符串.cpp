#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
char s[N],p[N];
int stk[N],f[N],ne[N],top;
int main()
{
    cin>>s+1>>p+1;
    for(int i=2,j=0;p[i];i++)
    {
        while(j&&p[j+1]!=p[i]) j=ne[j];
        if(p[j+1]==p[i]) j++;
        ne[i]=j;
    }
    int plen=strlen(p+1);
    for(int i=1,j=0;s[i];i++)
    {
        while(j&&p[j+1]!=s[i]) j=ne[j];
        if(s[i]==p[j+1])
        f[i]=j;
        stk[++top]=i;
        if(j==plen)
        {
            top-=plen;
            j=f[stk[top]];
        }
    }
    for(int i=1;i<=top;i++) cout<<s[stk[i]];
    return 0;
}