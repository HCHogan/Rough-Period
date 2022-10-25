#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=1000000;
int arr[N+5];
int a,n;

void work(int a,int n);

int main()
{
    cin>>a>>n;
    work(a,n);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
}

void work(int a,int n)
{
    arr[1]=a;
    int two=1,three=1;
    int tail=2;
    while(tail<=n)
    {
        int t1=arr[two]*2+1,t2=arr[three]*3+1;
        int t=min(t1,t2);
        if(t1<t2) two++;
        else three++;
        if(t==arr[tail-1]) continue;//这里改成等于好理解一点，就是重复的数字不要出现
        arr[tail++]=t;
    }
    cout<<arr[n];
}
//two,three是两个指针，指向要乘2和乘3的数字，如果数字小就可以放进去，当前数字完成乘的程序
//指针右移，指向下一个要被乘的数字，并且与上一个较大的数字继续比较，保证每两个数字都能比较到
//以此控制递增的特性