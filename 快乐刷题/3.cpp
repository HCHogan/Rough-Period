//21220513杨圣涵
#include<iostream>
using namespace std;
const int N=1010;

int n,cnt[N],maxnum;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        cnt[t]++;
        maxnum=max(maxnum,cnt[t]);
    }
    cout<<maxnum<<endl;
    return 0;
}