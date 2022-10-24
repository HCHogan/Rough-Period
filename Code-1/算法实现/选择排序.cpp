#include<iostream>
using namespace std;
void sort(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        int min=i;
        for(int j=i+1;j<len;j++)
        {
            if(arr[j]<arr[i]) min=j;
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

int main(){
    int n;
    cout<<"请输入数组大小"<<endl;
    cin>>n;
    int arr[n];
    cout<<"亲输入"<<n<<"个数字"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}