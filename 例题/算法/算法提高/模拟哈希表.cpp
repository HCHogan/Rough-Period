#include<iostream>
#include<set>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int h[N],n,m,w[i];
struct Node
{
    int key,a,b;
};
int find()
{
    int x;
    cin>>x;
    int k=(x%N+N)%N;
    while(h[k]!=INF&&h[k]!=x)
    {
        k++;
        if(k==N) k=0;
    }
    return k;
}
int main()
{
    memset(h,0x3f,sizeof h);
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            Node node={abs(w[i]+w[j]),i,j};
            int k=find(node.key);
        }
    }
}