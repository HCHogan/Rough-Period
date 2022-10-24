#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<int> add(vector<int> &A,vector<int> &B)
{
    vector<int>C;
    if(A.size()<B.size()) {
        return add(B,A);
    }
    int t=0;
    for(int i=0;i<=A.size()-1;i++)
    {
        t+=A[i];
        if(i+1<=B.size()) {t+=B[i];}
        C.push_back(t%10);
        if((t/=10)&&i+1==A.size())
        {
            C.push_back(1);
        }
    }
    while(C.back()==0&&C.size()>1)
    {
        C.pop_back();
    }
    return C;
}
int main()
{
    vector<int>A,B;
    string a,b;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
    {
        int tmp=a[i]-'0';
        A.push_back(tmp);
    }
    for(int i=b.size()-1;i>=0;i--)
    {
        int tmp=b[i]-'0';
        B.push_back(tmp);
    }
    vector<int>C=add(A,B);
    for(int i=C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }
    //cout<<C.size();
}