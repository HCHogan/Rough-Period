#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
typedef vector<int> VI;

VI sub(VI&A,VI&B)
{
    int t=0;
    VI C;
    for(int i=0;i<A.size();i++)
    {
        t=A[i]-t;
        if(i<B.size()) t-=B[i];
        C.push_back((t+10)%10);
        if(t<0) t=1;
        else t=0;
    }
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

VI div(VI&A,int b,int &R)
{
    int t=0;
    VI C;
    for(int i=0;i<A.size();i++)
    {
        R+=A[i];
        //R=R%b;
        t=R/b;
        C.push_back(t);
        R%=b;
        R*=10;
    }
    R/=10;
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

int main()
{
    VI A,C;
    int b,R=0;
    string a;
    cin>>a>>b;
    for(int i=0;i<a.size();i++)
    {
        A.push_back(a[i]-'0');
    }
    C=div(A,b,R);
    for(int i=C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }
    cout<<endl<<R;
}