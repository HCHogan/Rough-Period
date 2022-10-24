#include<iostream>
using namespace std;
int a[10001];
int n,k;
int q_select(int a[],int L,int R,int k)
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
    int lsum=j-L+1;
    if(k<=lsum) return q_select(a,L,j,k-lsum);
    return q_select(a,j+1,R,k);

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>k;
    q_select(a,1,n,k);
    cout<<q_select(a,1,n,k);
}