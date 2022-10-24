#include<iostream>
using namespace std;
int k,
int main()
{
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        int n,a[101][101],ha,la,hb,lb;
        cin>>n;
        for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) cin>>a[i][j];
        cin>>ha>>la>>hb>>lb;
        dfs(ha,la,hb,lb);
    }
}