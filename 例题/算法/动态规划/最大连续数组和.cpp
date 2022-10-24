#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> nums,nums1,nums2;
int main()
{
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int ans =-1e9;
    for(int i=0,last=0;i<nums.size();i++)
    {
        last=nums[i]+max(last,0);
        ans=max(ans,last);
    }
    cout<<ans<<endl;
    return 0;
}  //第二种方法 最大连续数组和有三种可能[L,mid],[mid+1,r]或者跨越 跨越的话
   //要从mid开始向左右找
int calc(int L,int R,vector<int> &nums1)     //vector这样传数组进函数
{
    if(L==R) return nums1[L];
    int mid=L+R>>1;
    int lmax=nums1[mid],lsum=0,rmax=nums1[mid+1],rsum=0;
    for(int i=mid;i>=L;i--)
    {
        lsum+=nums1[i];
        lmax=max(lmax,lsum);
    }
    for(int i=mid+1;i<=R;i++)
    {
        rsum=+nums1[i];
        rmax=max(rmax,rsum);
    }
    return (max(calc(L,mid,nums1),max(calc(mid+1,R,nums1),lsum+rsum)));
}
int main1()
{
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        nums1.push_back(x);
    }
    calc(0,nums1.size()-1,nums1);
    return 0;
}

struct Node
{
    int sum,target,ls,rs;
    //ls是前缀和 rs是后缀和 sum是区间总和 target是在中间的和
};
Node build(int l,int r,vector<int> &nums2)
{
    int v=max(nums2[l],0);
    if(l==r) return {nums2[l],v,v,v};
    int mid2=l+r>>1;
    Node L=build(l,mid2,nums2),R=build(mid2+1,r,nums2);
    Node res;
    res.ls=max(L.ls,L.sum+R.rs);
    res.rs=max(R.rs,R.sum+L.rs);
    res.sum=L.sum+R.sum;
    res.target=max(max(L.target,R.target),L.rs+R.ls);
    return res;

}
int main3()
{
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        nums2.push_back(x);
    }
    int t=-1e9;
    Node ans=build(0,nums2.size()-1,nums2);
    cout<<ans.target;
}
