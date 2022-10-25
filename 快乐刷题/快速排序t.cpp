#include<iostream>
using namespace std;
int a[10001];
int n;
int q_sort(int a[],int L,int R)
{
    if(L>=R) return 0;
    int flag=L+R>>1;
    int t=a[flag];
    int i=L-1;
    int j=R+1;
    while(i<j)
    {
        while(a[++i]<t);
        while(a[--j]>t);
        swap(a[i],a[j]);
    }
    q_sort(a,L,j);
    q_sort(a,j+1,R);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    q_sort(a,1,n);
    for(int i=1;i<=n;i++) cout<<a[i];
}