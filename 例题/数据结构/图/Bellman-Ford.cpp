#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int node_sum,edge_sum,end_node,start_node;
int w[N],u[N],v[N],dis[N],bak[N];
int main()
{
    cin>>node_sum>>edge_sum>>end_node;
    memset(dis,0x3f,sizeof dis);
    dis[start_node]=0;
    for(int k=1;k<=node_sum-1;k++)
    {
        for(int i=1;i<=node_sum;i++) bak[i]=dis[i];
        for(int i=1;i<=edge_sum;i++)
        {
            if(dis[v[i]]>dis[u[i]]+w[i])
                dis[v[i]]=dis[u[i]]+w[i];
        }
        bool check=false,check1=true;
        for(int i=1;i<=node_sum;i++)
        {
            if(bak[i]!=dis[i])
            {
                check=1;
                break;
            }
        }
        if(!check) break;
        for(int i=1;i<=edge_sum;i++)
        {
            if(dis[v[i]]>dis[u[i]]+w[i]) check1=0;
        }
        if(check1) break;
    }
}
