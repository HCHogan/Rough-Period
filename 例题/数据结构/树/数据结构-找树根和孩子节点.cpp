#include<iostream>
#include<cstring>
using namespace std;

int tree[101];
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        tree[y]=x; //y是x的孩子
    }
    int root;
    for(root=1;root<=n;root++)
    {
        if(tree[root]==0) break;  //找到孩子最多的节点
    }
    int maxroot, cnt=0, maxcnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(tree[j]==i) cnt++;
        }
        if(cnt>maxcnt) maxcnt=cnt;
        maxroot=i;
    }
    cout<<root<<endl<<maxroot<<endl;
    for(int i=1;i<=n;i++)
    {
        if(tree[i]==maxroot) cout<<i<<" ";
    }
    return 0;
}