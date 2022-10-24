#include<iostream>
using namespace std;
const long long int N=1e9;
int a[N];
void quick_sort(int* a, int L, int R )
{
    if(L>=R) return;
    int ref=(L+R)>>1;
    int i=L-1,j=R+1;
    while(i<j){
        while(a[++i]<a[ref]);
        while(a[--j]>a[ref]);
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    quick_sort(a,L,j);
    quick_sort(a,j+1,R);
}

int main()
{
    int n;
    cin>>n;
    //int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}