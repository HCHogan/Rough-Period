#include<iostream>
#include<cstring>
using namespace std;
int n,a[10001];
char s[10001];
int main()
{
    cin>>s>>k;
    len=strlen(s);
    while(k--)
    {
        for(int i=0;i<=len-2;i++)
        {
            if(s[i]>s[i+1])
            {
                for(int j=i;j<=n;j++)
                {
                    s[j]=s[j+1];
                }
                slen--;
                break;
            }
            if(i==len-2) len--;
        }
    }
    for(int i=0;i<len;i++) cout<<s[i];
    return 0;
}