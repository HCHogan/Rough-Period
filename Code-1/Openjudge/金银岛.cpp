#include<iostream>
#include<algorithm>
using namespace std;
const int N=10010;
struct Node{
    int v,n;
    double val;
    bool operator< (const Node &x) const{
        return val>x.val;
    }
};

int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        double ans=0;
        int w,n;
        struct Node a[N];
        cin>>w>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].n>>a[i].v;
            a[i].val=(a[i].v+0.0)/(a[i].n+0.0);
        }
        sort(a+1,a+n+1);
        int i=1;
        for(int i=1;i<=n;i++)
        {
            if(w<a[i].n)
            {
                ans+=(w+0.0)*a[i].val;
                w=0;
                break;
            }
            else
            {
                w-=a[i].n;
                ans+=a[i].v;
            }
        }
        printf("%.2lf\n",ans);
    }
}