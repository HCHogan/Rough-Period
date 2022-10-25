#include<iostream>
#include<cstring>
using namespace std;
const int N=10001;
char a[N],b[N],t1[N],t2[N];
int f[N][N];
int x,y,ans;
int main()
{
    scanf("%s%s",t1,t2);
    x=strlen(t1);
    y=strlen(t2);
    for(int i=1;i<=x;i++) a[i]=t1[i-1];
    for(int i=1;i<=y;i++) b[i]=t2[i-1];
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<y;j++)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])
                f[i][j]=max(f[i-1][j-1]+1,f[i][j]);
            ans=max(ans,f[i][j]);
        }
    }
    cout<<ans;
    return 0;
}