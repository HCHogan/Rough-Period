#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int ne[N];        //pattern 模式串
char s[N],p[N];
int cnt;

int main()
{
    scanf("%s%s",s+1,p+1);
    for(int i=2,j=0;p[i];i++)
    {
        while(j&&ne[j+1]!=p[i]) j=ne[j];
        if(ne[j+1]==p[i]) j++;
        ne[i]=j;
    }
    for(int i=1,j=0;s[i];i++)
    {
        while(j&&ne[j+1]!=s[i]) j=ne[j];
        if(ne[j+1]==s[i]) j++;
        if(j=strlen(s+1)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}