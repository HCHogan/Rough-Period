#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;

int father[N],pa,pb;
int n,m;
int res;

int getm(int x,int y)
{
    return x*n+y;
}

int find(int k)
{
    if(k!=father[k]) father[k]=find(father[k]);
    return k;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n*n;i++)
        father[i]=i;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        char d;
        int x,y,a,b;
        cin>>x>>y>>d;
        x--,y--;
        int a=getm(x,y);
        if(d=='D') b=getm(x,y+1);
        else b=getm(x+1,y);
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)
        {
            int res=i;
            break;
        }
        else
        {
            father[pa]=pb;
        }
    }
    if(res) cout<<res<<endl;
    else puts("draw");
    return 0;
}