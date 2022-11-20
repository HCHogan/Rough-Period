#include<iostream>
using namespace std;
int n;
const int N=1000000;
int a[N];
long long ans=0;
void merge(int* arr,int L, int R)
{
    if(L>=R) return;
    int mid=(L+R)>>1;
    merge(arr,L,mid),merge(arr,mid+1,R);
    int i=L,j=mid+1;
    int temp[R-L+10];
    int k=0;
    while(i<=mid&&j<=R){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=R) temp[k++]=arr[j++];
    for(int i=L,x=0;i<=R&&x<=k;) arr[i++]=temp[x++];
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    merge(a,1,n);
    cout<<ans;
}