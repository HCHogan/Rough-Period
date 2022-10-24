#include<iostream>
#include<vector>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int n,m;
int f[N];

struct Node
{
    int v,w;
};

vector<Node> nodes;

int main()
{
    cin>>m>>n;
    while(n--)
    {
        int v,w,s;
        for(int k=1;k<=s;k*=2)
        {
            s-=k;
            nodes.push_back({v*k,w*k});
        }
        if(s) nodes.push_back({v*s,w*s});
    }
    for(auto node:nodes)
    {
        for(int j=m;j>=node.v;j++)
        {
            f[j]=max(f[j],f[j-node.v]+node.w);  //O(nmlogs)
        }
    } 
    cout<<f[m]<<endl;       //因为是01背包 每个都有可能选到和选不到 所以可以拆分
    return 0;               //组合是完全的
}