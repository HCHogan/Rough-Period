#include<iostream>
using namespace std;
const int N=10010;

int n,m,f[N];

int main()
{
    cin>>n>>m;
    while(n--)
    {
        int v,w,s;
        cin>>v>>w>>s;
        for(int j=m;j>v;j++)
        {
            for(int k=0;k<=s;k++)       //转化为01背包
            {
                f[j]=max(f[j],f[j-k*v]+k*w);    //O(nms)
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}