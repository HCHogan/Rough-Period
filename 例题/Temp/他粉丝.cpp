#include<iostream>
using namespace std;
int n,na,nb,m,a[10001],b[10001],ansa=0,ansb=0;
int main()
{
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++) cin>>a[i];
    for(int i=0;i<nb;i++) cin>>b[i];
    for(int i=0;i<n;i++)
    {
        int x=i % na;
        int y=i % nb;
        if(a[x]==b[y]) continue;
        if(a[x]-b[y]==-2) ansa++;
        if(a[x]-b[y]==-5) ansb++;
        if(a[x]-b[y]==2) ansb++;
        if(a[x]-b[y]==-3) ansa++;
        if(a[x]-b[y]==5) ansa++;
        if(a[x]-b[y]==3) ansb++;
    }
    if(ansa==ansb) cout<<"draw";
    if(ansa>ansb) cout<<'A';
    else cout<<'B';
    return 0;
}