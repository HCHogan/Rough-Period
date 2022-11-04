#include<iostream>
#include<string>
using namespace std;
int a[300];
int n,k,tail;
string str;
int main()
{
    cin>>str>>k;
    n=str.length();
    tail=n;
    for(int i=1;i<=n;i++) {a[i]=str[i-1]-'0';}
    while(k--)
    {
        for(int i=1;i<=n-1;i++)
        {
            if(a[i+1]<a[i])
            {
                for(int j=i;j<n;j++)
                {
                    a[j]=a[j+1];
                }
                tail--;
                break;
            }
            if(i==n-1) tail--;
        }
    }
    int st=1;
    while(a[st]==0&&st<tail) st++;
    for(int i=st;i<=tail;i++)
    {
        cout<<a[i];
    }
}