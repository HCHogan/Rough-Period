#include<iostream>
using namespace std;
int n,q,a[10001],ulink;
void buildset(int n)
{
    for(int i=1;i<=n;i++) a[i]=i;
    return;
}
int findx(int k)
{
    if(a[k]!=k) return finx[a[k]];
    return k;
}
int mergei(int x,int y)
{
    if(a[x]!=a[y]) a[y]=x;    //优化a[x]=a[y];
}
int main()
{
    cin>>n;
    buildset(n);
    cin>>u;
    for(int i=1;i<=ulink;i++)
    {
        int x,y;
        cin>>x>>y;
        if(findx(x)!=findx(y))
            mergei(x,y);
    }
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(findx(x)!=findx(y)) cout<<"yes";
        else cout<<"no";
    }
    cout<<endl;
}