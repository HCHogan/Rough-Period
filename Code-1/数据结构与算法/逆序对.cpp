#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL ans=0;
const LL N=5e5+10;
void merge(int * arr,int min,int mid,int max)
{
    int temp[N];//临时数组用来排序
    int i=min,j=mid+1,k=0;
    while(i<=mid&&j<=max)
    {
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else {
            temp[k++]=arr[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=max) temp[k++]=arr[j++];
    i=min;
    for(int x=0;(x<k)&&(i<=max);)
    {
        arr[i++]=temp[x++];//排好序后放入原数组
    }
}

void mergeSort(int *arr,int min,int max)
{
    int mid=(min+max)/2;
    if(min<max)
    {
        mergeSort(arr,min,mid);
        mergeSort(arr,mid+1,max);
        merge(arr,min,mid,max);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[N];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    cout<<ans<<endl;
}