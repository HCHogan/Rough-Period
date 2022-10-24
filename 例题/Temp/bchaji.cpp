#include<iostream>
using namespace std;
const int N=10001;
int k[N],father[i],node_sum,edge_sum;
int buildset(int n)
{
    for(int i=1;i<=n;i++) father[i]=i;
}
int findx(int n)
{
    if(father[n]!=n) return father[n];
    return n;
}
int merge_i(int a,int b)
{
    if(findx(a)!=findx(b))
    father[a]=father[b];
}
int main()
{
    cin>>node_sum;
    buildset(node_sum);
    cin>>edge_sum;
    for(int i=1;i<=edge_sum;i++)
    {
        int x,y;
        cin>>x>>y;
        merge_i(x,y);
    }
    for()
}
