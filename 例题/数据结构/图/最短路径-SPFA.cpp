#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
struct Edge
{
    int next;
    int to;
    int wei;
}edge[N];
queue<int> que;
int head[N],node_sum,num_edge=0,edge_sum,book[N],dis[N],end_node,start_node;
int pre[N];
void add(int from,int to,int wei)
{
    edge[++num_edge].next=head[from];
    edge[num_edge].wei=wei;
    edge[num_edge].to=to;
    head[from]=num_edge;
}
int main()
{
    cin>>node_sum>>edge_sum>>start_node>>end_node;
    memset(head,0,sizeof head);
    for(int i=1;i<=edge_sum;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        //无向图加上add(y,x,z);
    }
    memset(book,0,sizeof book);
    memset(dis,0x3f,sizeof dis);
    dis[start_node]=0;
    que.push(start_node);
    book[start_node]=1;
    while(que.empty())
    {
        int cur=que.front();
        int i=head[cur];
        book[cur]=0;
        while(i)
        {
            int np=edge[i].to;
            if(dis[np]>dis[cur]+edge[cur].wei)
            {
                dis[np]=dis[cur]+edge[cur].wei;
                pre[np]=cur;
                if(!book[np])
                {
                    que.push(np);
                    book[np]=1;
                }
            }
            i=edge[i].next;
        }
        que.pop();
    }
    cout<<dis[end_node];
    return 0;
}