#include<cstdio>
#include<cstring>
using namespace std;
const int N=100010,INF=0x3f3f3f3f;
int sum[2*N];
int ai,m,n;
int dat[2*N];
int main()
{
    scanf("%d%d",&n,&ai);
    for(int i=0;i<n;i++)
    {
        scanf("%d",dat+i);
    }
    while(ai--)
    {
        memset(sum,0,sizeof sum);
        int l,r,maxnum=0;
        scanf("%d%d",&l,&r);
        for(int i=l;i<=r;i++)
        {
            sum[dat[i]]++;
        }
        for(int i=0;i<=10000;i++)
        {
            if(sum[i]>1)
            {
                maxnum+=sum[i]-1;
            }
        }
        printf("%d\n",r-l+1-maxnum);
    }
    return 0;
}