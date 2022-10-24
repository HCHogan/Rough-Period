#include<iostream>
using namespace std;
#include<vector>
vector<int> add(vector<int> &A,vector<int> &B)
{
    vector<int>C;
    int t=0;
    for(int i=0;i<=A.size()-1;i++)
    {
        t+=A[i];
        if(i+1<=B.size()) {t+=B[i];}
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(1);
    while(C.back()==0&&C.size()>1)
    {
        C.pop_back();
    }
    return C;
}

int main()
{
    vector<int>n[5010];
    int N;
    cin>>N;
    n[1].push_back(1);
    n[2].push_back(2);
    for(int i=3;i<=N;i++)
    {
        n[i]=add(n[i-1],n[i-2]);
    }
    for(int i=n[N].size()-1;i>=0;i--)
    {
        cout<<n[N][i];
    }
}