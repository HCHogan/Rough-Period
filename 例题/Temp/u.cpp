#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
int a[5][5],w[2][5],n;   //w[0][i]存第i行最大的数的值 w[1][i]存第i行最大数的列数
int main()
{
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++) cin>>a[i][j];
    for(int i=1;i<=5;i++)
    {
        int t=-INF;
        for(int j=1;j<=5;j++)
        {
            if(a[i][j]>t)
            {
                t=a[i][j];
                w[0][i]=t;
                w[1][i]=j;
            }
        }
    }
    int cnt=0;
    bool ans=0;
    for(int i=1;i<=5;i++)
    {
        int y=w[1][i];
        cnt=0;
        for(int j=1;j<=5;j++)
        {
            if(a[j][y]<w[0][i]) cnt++;
            ans=0;
        }
        if(cnt==0) 
        {
            cout<<i<<" "<<y<<" "<<w[0][i]<<endl;
            ans=1;
        }
    }
    if(ans) cout<<"not found";
}