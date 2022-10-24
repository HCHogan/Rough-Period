#include<iostream>
using namespace std;
int n,a[10001],temp[10001];
int merge_sort(int a[],int L,int R)
{
    if(L>=R) return 0;
    int mid=(L+R)>>1;
    merge_sort(a,L,mid),merge_sort(a,mid+1,R);
    int i=L,j=mid+1,k=1;
    while(i<=mid&&j<R)
    {
        if(a[i]<=a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while(i<=mid) temp[k++]=a[i++];
    while(j<=R) temp[k++]= a[j++];
    for(int i=L,k=1;i<=R;i++,k++) a[i]=temp[k];

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    merge_sort(a,1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}