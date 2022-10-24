#include<iostream>
using namespace std;
void quick_sort(int *arr,int left,int right)
{
    int ref=arr[(left+right)/2];
    int i=left,j=right;
    while(i<j)
    {
        while(arr[i]<ref) i++;
        while(arr[j]>ref) j--;
        if(i<j){//我一开始写i<j
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            //我一开始没写
        }
    }
    if(j>left) quick_sort(arr,left,j);
    if(i<right) quick_sort(arr,j+1,right);//细想不难发现，j将永远在i的左边!
}

int main(){
    cout<<"请输入数组个数："<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"请输入"<<n<<"个整数"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}