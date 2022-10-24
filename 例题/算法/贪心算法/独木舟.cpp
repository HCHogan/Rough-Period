#include<iostream>
#include<algorithm>
using namespace std;
int n,a[10001],w,ans;
//贪心和排序经常一起出现
int main()
{
    cin>>w>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,greater<int>());    //从大到小排序这样写
    int L=1,R=n;
    while(L<=R)
    {
        if(a[L]+a[R]<=w) L++,R--;
        else L++;
        ans++;
    }
    cout<<ans;
    return 0;
}