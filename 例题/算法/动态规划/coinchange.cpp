#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int a[]={2,5,7},f[N];        //f[j]一共占了j个空间 最少用了多少硬币

int main()
{
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for(int i=0;i<=27;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i-a[j]<0) continue;
            f[i]=min(f[i-a[j]]+1,f[i]);
        }
    }
    cout<<f[27]<<endl;
    return 0;
}