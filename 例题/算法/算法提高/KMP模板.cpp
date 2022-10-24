#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
char s[N],sub[N];
int ne[N];
int ns,nsub,cnt;
int main()
{
    scanf("%s%s",s+1,sub+1);
    for(int i=2,j=0;sub[i];i++)
    {
        while(j&&sub[j+1]!=sub[i]) j=ne[j];
        if(sub[j+1]==sub[i]) j++;
        ne[i]=j;
    }
    for(int j=0,i=1;s[i];i++)
    {
        while(j&&sub[j+1]==s[i]) j=ne[j];
        j++;
        if(j==strlen(sub)-1)
        {
            cnt++;
            cout<<i-strlen(sub)+1<<endl;
            j=ne[j];
        }
    }
    for(int i=1;i<=strlen(sub);i++) cout<<ne[i]<<" ";
    cout<<endl<<cnt<<endl;
    return 0;
}