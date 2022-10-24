#include<iostream>
using namespace std;
void merge(int * arr,int min,int mid,int max)
{
    int * temp=new int [max-min+1];//临时数组用来排序
    int i=min,j=mid+1,k=0;
    while(i<=mid&&j<=max)
    {
        if(arr[i]<arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=max) temp[k++]=arr[j++];
    i=min;
    for(int x=0;(x<k)&&(i<=max);)
    {
        arr[i++]=temp[x++];//排好序后放入原数组
    }
    delete[] temp;
    temp=NULL;
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
    cout<<"请输入数组大小"<<endl;
    cin>>n;
    cout<<"请输入"<<n<<"个数字"<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}