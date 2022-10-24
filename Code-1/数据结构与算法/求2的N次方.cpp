#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<int> VI;

VI mul(VI &A,int b)
{
    VI C;
    int t=0;
    for(int i=0;i<A.size()||t;i++)
    {
        if(i<A.size()) t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}
int main()
{
    int N;
    VI ans;
    ans.push_back(1);
    cout<<"请输入N的值"<<endl;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        ans=mul(ans,2);
    }
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i];
    }
}