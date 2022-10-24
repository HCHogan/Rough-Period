#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int node_sum,edge_sum,num_edge,dis[N],start_node,end_node,cow[N],cow_sum;
bool book[N];
struct Edge
{
    int next;
    int to;
    int wei;
}edge[N];
int add(int from,int to,int wei)
{
    
}
int main()
{
    cin>>node_sum>>edge_sum>>cow_sum;
    memset(cow,0,sizeof cow);
    for(int i=1;i<=cow_sum;i++) cin>>cow[i];
    for(int i=1;i<=edge_sum;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
}