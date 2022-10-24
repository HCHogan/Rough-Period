#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
struct Node{
    int t1,t2;
    bool operator< (const Node& x) const{
        return t1<x.t1;
    }
};
int n,maxnum=-INF,res=0,a,b;
vector<Node> v1,v2;
void calc(vector<Node>& v,int n)
{
    if(n==0) return;
    priority_queue<int,vector<int>,greater<int>> heap;
    for(auto x:v)
    {
        int t1=x.t1,t2=x.t2;
        if(heap.empty())
        {
            heap.push({t2});
            res++;
        }
        else if(heap.top()<t1)
        {
            heap.pop();
            heap.push({t2});
            res++;
        }
        else if(v.size()<n)
        {
            heap.push(t2);
            res++;
        }
    }
    return;
}
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=a;i++)
    {
        int x,y;
        cin>>x>>y;
        v1.push_back({x,y});
    }
    for(int i=1;i<=b;i++)
    {
        int x,y;
        cin>>x>>y;
        v2.push_back({x,y});
    }
    for(int i=0;i<=n;i++)
    {
        calc(v1,i),calc(v2,n-i);
        maxnum=max(maxnum,res);
        res=0;
    }
    cout<<maxnum<<endl;
    return 0;
}