#include<iostream>
using namespace std;
int ans=0;
int i,len;
string a,b;
void change()
{
    if(i==0)
    {
        if(a[i]=='1') a[i]='0';
        else if(a[i]=='0') a[i]='1';
        if(a[i-1]=='0') a[i-1]='1';
        else if(a[i-1]=='1') a[i-1]='0';
    }
    else if(i==len-1)
    {
        if(a[i]=='1') a[i]='0';
        else if(a[i]=='0') a[i]='1';
        if(a[i-1]=='0') a[i-1]='1';
        else if(a[i-1]=='1') a[i-1]='0';
    }
    else{
        if(a[i]=='1') a[i]='0';
        else if(a[i]=='0') a[i]='1';
        if(a[i+1]=='0') a[i+1]='1';
        else if(a[i+1]=='1') a[i+1]='0';
        if(a[i-1]=='0') a[i-1]='1';
        else if(a[i-1]=='1') a[i-1]='0';
    }
}
int main()
{
    cin>>a>>b;
    len=a.length();
    for(i=0;i<len;i++)
    {
        if(a[i]!=b[i]&&a[i-1]!=b[i-1])
        {
            ans++;
            change();
        }
    }
    for(i=0;i<len;i++)
    {
        if(a[i]!=b[i]&&a[i+1]!=b[i+1])
        {
            ans++;
            change();
        }
    }
    if(!a.compare(b)) cout<<ans;
    else cout<<"impossible";
}