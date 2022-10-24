#include<iostream>
using namespace std;
void quick_sort(int *arr,int left,int right)
{
    if(left>=right) return;
    int ref=arr[(left+right)/2];
    int i=left-1,j=right+1;
    while(i<j)
    {
        while(arr[++i]<ref);//不能++写在后面
        while(arr[--j]>ref);//当i与j指向同一个数字且为ref时，死循环，ij都不动
        if(i<j){//现在上面是越界定义，且为do while，我一开始写i<j
            int temp=arr[i];//而我之前是边界定义，且while，必须写i<=j!
            arr[i]=arr[j];
            arr[j]=temp;
            //看这里是否要自增自减
        }
    }
    quick_sort(arr,left,j);
    quick_sort(arr,j+1,right);//细想不难发现，j将永远在i的左边!
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