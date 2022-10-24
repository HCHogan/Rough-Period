#include<iostream>
using namespace std;
const int N=10010;
template<typename T>
void qsort(T a[],int L,int R)
{
    if(L>=R) return;
    int i=L-1,j=R+1;
    int pivot=a[L];
    while(i<j)
    {
        while(a[++i]<pivot);
        while(a[--j]>pivot);
        if(i<j) swap(a[i],a[j]);
    }
    qsort(a,L,j),qsort(a,j+1,R);
    return;
}
int test01()
{
    int n;
    char a[N];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    qsort(a,1,n);
    for(int i=1;i<=n;i++) cout<<a[i];
    return 0;
}
int main()
{
    test01();
    return 0;
}