#include<iostream>
using namespace std;
void insertSort(int* arr,int len)
{
    for(int i=1;i<len;i++)
    {
        int key=arr[i];
        int j=i-1;//与前一个开始比较
        while(j>=0&&key<arr[j])//实现：主要数组的后一个元素比前一个元素小，那么这个前面的元素就后移覆盖后面的元素，而在一开始的实验元素储存在key中，无数据丢失
        {
            arr[j+1]=arr[j];
            j--;
        }//因此当他为最大时无需更换，最小时自动更换到最前排
        arr[j+1]=key;//交换完成后j为当前应插入的位置，--后为前一位置，因此取j+1赋值
    }
}

int main(){
    int n;
    cout<<"请输入数组容量"<<endl;
    cin>>n;
    cout<<"请输入"<<n<<"个数"<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertSort(arr,n);
    cout<<"排序结果为：";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}