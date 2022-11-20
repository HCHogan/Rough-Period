#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
int main()
{
    int n,ans=0;
    cin>>n;
    int a[N];
    bool book[N]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(book[i]==false)
        {
            book[i]=true;
            ans++;
            int temp=a[i];
            for(int j=i+1;j<=n;j++)
            {
                if((a[j]>temp)&&(book[j]==false))
                {
                    book[j]=true;
                    temp=a[j];
                }
            }
        }
    }
    cout<<ans;
}