#include<iostream>
using namespace std;
const long long N=5e5,ans=0;
int arr[N];
void merge_sort(int* arr, int L,int R)
{
    if(L>=R) return;
    int temp[R-L+10];
    int mid=(L+R)>>1;
    int i=L,j=mid+1,k=0;
    merge_sort(arr,L,mid);
    merge_sort(arr,mid+1,R);
    while(i<=mid&&j<=R)
    {
        if(arr[i]<=arr[j]) {temp[k++]=arr[i++];}//一定要小于等于，逆序对必须严格逆序!
        else {temp[k++]=arr[j++];ans+=mid-i+1;}
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=R) temp[k++]=arr[j++];
    for(int i=L,x=0;(i<=R)&&(x<k);i++,x++) {arr[i]=temp[x];}
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    cout<<ans;
}