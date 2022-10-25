#include<iostream>
using namespace std;
const int N=10001;
int a[N],b[N],n,len=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>b[len]) b[++len]=a[i];
        else
        {
            int *p=upper_bound(a+1,a+i+1,a[i]);
            if(p==a+len) continue;
            *p=a[i];
        }
    }
    cout<<len<<endl;
    for(int i=1;i<=len;i++) cout<<b[i]<<" ";
    return 0;
}
int idx(int L,int R,int x)
{
    while(L<R)
    {
        int mid=L+R+1>>1;
        if(b[mid]<x) L=mid;      //当b[mid]<x的时候 说明要找的数在右面但是此时
        else R=mid-1;            //因为mid=L+R+1>>1所以L有可能我们要找的这个数
    }
}
/*  L+R+1>>1保证了mid要么是最中间那个 要么是中间靠右那个
    当L和R相邻时  如果L=R>x那么mid=R R=mid-1=L 往左边缩
                如果L<R且R>x 那么往右边缩
*/
