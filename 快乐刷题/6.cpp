//21220513杨圣涵
#include<iostream>
using namespace std;
const int N=100010;

int a[N],b[N],flag[N];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        flag[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>i)
        {
            cout<<-1<<endl;
            return 0;
        }
        for(int j=a[i-1];j<=1e9;j++)
        {
            if(flag[j]==0)
            {   
                b[i]=j;
                flag[j]++;
                flag[a[i]]-=1;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}