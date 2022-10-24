//用vector实现 方便
#include<iostream>
#include<vector>
using namespace std;
const int N=10001;
struct Node
{
    int v;          //节点编号
    int w;          //权
};
vector<Node> h[N];   //类似于一个二维数组 不过每个元素是结构体
int n,m;
int main()    //尾插法
{
    cin>>n>>m;          //n为节点数，m为边数
    for(int i=1;i<=m;i++)
    {
        int a;          //起点
        int v,w;
        cin>>a>>v>>w;
        h[a].push_back({v,w});
        //h[v].push_back({a,w});    无向图就加这一行
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"起点："<<i;
        for(auto x:h[i])      //用x来自动遍历h[i] x为结构体
        {
            printf("%d %d  |  ",x.v,x.w);
        }
        puts("");   //换行
    }
    return 0;
}