#include<iostream>
using namespace std;
int a[100000][10000]={0};
int h[100000];
int ans=0,H=-1;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        if(h[i]==0) break;
        else{
            for(int j=1;j<=h[i];j++)
            {
                a[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        H=max(H,h[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=H;j++)
        {
            if(a[i][j]==1&&a[i+1][j]==0) ans++;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans;
}
//for(int i=1;i<=n;i++) if(h[i]>h[i-1]) ans+=h[i]-h[i-1];
//只要计算两边高度的差值就行