#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int n,m,f[N][N];
char strA[N],strB[N];
int main()
{
    cin>>n>>m;
    cin>>strA>>strB;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(strA[i]==strB[j]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
}