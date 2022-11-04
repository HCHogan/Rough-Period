#include<iostream>
using namespace std;
int main()
{
    int tree[101]={0};
    int n,m,x,y,root;//y为子节点
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        tree[y]=x;
    }
    for(int i=1;i<=n;i++)
    {
        if(tree[i]==0){
            root=i; 
            break;
        }
    }
    cout<<root<<endl;
    int maxroot,cnt,maxcnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        for(int j=i;j<=n;j++)
        {
            if(tree[j]==i) cnt++;
        }
        if(cnt>maxcnt){
            maxcnt=cnt;
            maxroot=i;
        }
    }
    cout<<maxroot<<endl;
    for(int i=1;i<=n;i++)
    {
        if(tree[i]==maxroot) cout<<i<<" ";
    }
}
// 8 7
// 4 1
// 4 2
// 1 3
// 1 5
// 2 6
// 2 7
// 2 8