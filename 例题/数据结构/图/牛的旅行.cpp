#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=10001;
double node_sum,g[N][N],maxdis_from[N],x[N],y[N],maxnum=999999.9;   //xy是坐标
double dist(int i,int j)            //maxdis是从第1个点开始最远的距离
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int main()
{
    cin>>node_sum;
    for(int i=1;i<=node_sum;i++)
        cin>>x[i]>>y[i];
    char c;
    for(int i=1;i<=node_sum;i++)
    {
        for(int j=1;j<=node_sum;i++)
        {
            cin>>c;
            if(c=='1')
                g[i][j]=dist(i,j);
            else
                g[i][j]=maxnum;
        }
    }
    for(int k=1;k<=node_sum;k++)
        for(int i=1;i<=node_sum;i++)
            for(int j=1;j<=node_sum;j++)
                if(i!=j&&i!=k&&j!=k)
                    if(g[k][i]<maxnum-1&&g[k][j]<maxnum-1&&g[k][i]+g[k][j]<g[i][j])
                        g[i][j]=g[k][i]+g[k][j];
    memset(maxdis_from,0,sizeof maxdis_from);
    for(int i=1;i<=node_sum;i++)
        for(int j=1;j<=node_sum;j++)
            if(g[i][j]>maxdis_from[i])
                maxdis_from[i]=g[i][j];
    double minnum=999999.9;
    for(int i=1;i<=node_sum;i++)
        for(int j=1;j<=node_sum;j++)
        {
            if(i!=j&&g[i][j]>maxnum-1)
            {
                double temp=dist(i,j);
                if(maxdis_from[i]+maxdis_from[j]+temp<minnum)
                    minnum=maxdis_from[i]+maxdis_from[j]+temp;
            }
        }
    for(int i=1;i<=node_sum;i++)            //多余的嘛？看不懂
        if(maxdis_from[i]>minnum)
            minnum=maxdis_from[i];
    printf("%.6lf",minnum);
    return 0;
}
