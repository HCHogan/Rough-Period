#include<iostream>
#include<cstring>
using namespace std;
const int N=100;
char a[N];
char b[N];
char ori[N];
int n,len,ans=0;
void change(int i)
{
    a[i]^=1;
    if(i==0)
    {
        a[i+1]^=1;
    }
    else if(i==len-1)
    {
        a[i-1]^=1;
    }
    else
    {
        a[i-1]^=1;
        a[i+1]^=1;
    }
}
int main()
{
    cin>>ori>>b;
    len=strlen(ori);
    for(int j=1;j<=2;j++)
    {
        strcpy(a,ori);
        ans=0;
        if(j==1)
        {
            for(int i=0;i<len-1;i++)
            {
                if(a[i]!=b[i])
                {
                    change(i+1);
                    ans++;
                }
            }
            if(a[len-1]==b[len-1]) break;
        }
        else if(j==2)
        {
            change(0);
            ans++;
            for(int i=0;i<len-1;i++)
            {
                if(a[i]!=b[i])
                {
                    change(i+1);
                    ans++;
                }
            }
        }
    }
    if(a[len-1]==b[len-1]) cout<<ans;
    else cout<<"impossible";
}