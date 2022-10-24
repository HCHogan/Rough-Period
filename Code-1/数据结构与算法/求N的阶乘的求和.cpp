//NOIP 1998
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<int> VI;

VI mul(VI &A,int b)
{
    int t=0;
    VI C;
    for(int i=0;i<A.size()||t;i++)
    {
        if(i<A.size()) t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

VI add(VI &A,VI &B)
{
    VI C;
    int t=0;
    if(A.size()<B.size()) return add(B,A);
    for(int i=0;i<A.size();i++)
    {
        t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(1);
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

int main()
{
    int N;
    VI C,D;
    C.push_back(1);
    D.push_back(0);
    cout<<"请输入N的值"<<endl;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        C=mul(C,i);
        D=add(C,D);
    }
    for(int i=D.size()-1;i>=0;i--)
    {
        cout<<D[i];
    }
}