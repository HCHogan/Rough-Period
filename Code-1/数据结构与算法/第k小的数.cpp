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

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    int ans=1;
    // for(int i=1;i<n;i++)
    //     {
    //         if(a[i]>a[i-1]) ans++;
    //         //if(ans==k) cout<<a[i];return 0;
    //     }
    if(k==1) cout<<a[0];
    //else if(k>ans) cout<<"NO RESULT";
    else{
        //ans=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1]) ans++;
            if(ans==k) {cout<<a[i];return 0;}
        }
    }
    if(k>ans) cout<<"NO RESULT";
}