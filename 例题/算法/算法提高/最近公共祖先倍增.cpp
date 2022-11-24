#include<iostream>
#include<vector>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int dep[N],fa[N][N];        //dep[i]表示标号为i的那个节点的深度
vector<int> e[N];           //fa[p][i]表示编号为p的节点向上条2^i层所到的点
//vector邻接表矩阵存图
int dfs(int p,int father)//传入当前节点和father 防止往回走
{
    fa[p][0]=father;
    dep[p]=dep[father]+1;
    for(int i=1;i<=19;i++)      //19取决于数据个数 自己算
    {
        fa[p][i]=fa[fa[p][i-1]][i-1];   //0是哨兵 无意义
    }
    for(int v : e[p])
    {
        if(v!=father) dfs(v,p);     //继续深搜他的孩子
    }
}
