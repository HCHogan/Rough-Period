#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
char s[N],sub[N];
int ne[N];
int n,m,cnt=0;
int main()
{
    scanf("%s%s",s+1,sub+1);
    int sublen=strlen(sub+1);
    for(int i=2,j=0;sub[i];i++)
    {
        while(j&&sub[j+1]!=sub[i]) j=ne[j];
        if(sub[j+1]==sub[i]) j++;
        ne[i]=j;
    }
    for(int i=1,j=0;s[i];i++)
    {
        while(j&&sub[j+1]!=s[i]) j=ne[j];
        if(sub[j+1]==s[i]) j++;
        if(j==sublen)
        {
            cnt++;
            j=0;            //kmp模板这里是j=ne[j];
        }
    }
    cout<<cnt<<endl;
    return 0;
}