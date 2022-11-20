#include<iostream>
#include<cmath>
using namespace std;
const int N=200;
const int INF=0x3f3f3f3f;
int main()
{
    int cyc_num=0;
    int n,k;
    int a[N];
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int j=i%k;
        if(a[i]==a[j]) cyc_num++;
    }
    if(cyc_num==n)
    {
        cout<<"0"<<endl;
        return 0;
    }
    int head=0,tail=k-1;
    int index=1;
    int ans_arr[k+10];
    for(;tail<=n-1;head++,tail++)//框一个基准区间
    {

        int diff_num=0;

        for(int i=0,l=0;i<n;i++,l++)
        {
            l%=k;
            l+=head;
            if(a[l]!=a[i]) diff_num++;
        }
        ans_arr[index++]=diff_num;
    }
    int ans=INF;
    for(int i=1;i<index;i++)
    {
        ans=min(ans,ans_arr[i]);
    }
    cout<<ans<<endl;
}