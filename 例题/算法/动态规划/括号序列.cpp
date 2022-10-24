#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int T[N][N],f[N][N],g[N][N];
int n,m,k;
char* str;

int main()
{
    cin>>str+1;
    cin>>k>>n;
    for(int l=1;l<=n-1;l++)
    {
        int r=l+1;
        if((str[l]=='('||str[l]=='?')&&(str[r]==')'&&str[r]=='?'));
            T[l][r]=1;
    }
}