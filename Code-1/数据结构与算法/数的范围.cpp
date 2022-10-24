#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        int x;
        cin>>x;
        int L=-1,R=n;
        while(L+1!=R)
        {
            int mid=(L+R)>>1;
            if(a[mid]<x) L=mid;
            else R=mid;
        }
        if(a[R]!=x) cout<<"-1 -1";
        else {cout<<R<<" ";
            L=-1;R=n;
            while(L+1!=R)
            {
                int mid=(L+R)>>1;
                if(a[mid]>x) R=mid;
                else L=mid;
            }
            cout<<L<<endl;
        }
    }
}