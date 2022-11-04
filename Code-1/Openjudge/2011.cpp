#include<iostream>
#include<vector>
using namespace std;
int a;
vector<int> ch;

vector<int> work(int n)
{
    int mid=n>>1;
    vector<int>v1,v2;
    if(n==1){
        v1.push_back(1);
        v1.push_back(1);
        v1.push_back(0);
        v1.push_back(2);
        // v2.push_back(1);
        // v2.push_back(1);
        // v2.push_back(0);
        // v2.push_back(2);
        return v1;
    }
    v1=work(mid),v2=work(n-mid);
    vector<int> temp;
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v2.size();j++)
        {
            temp[i+j]+=v1[1]*v2[j];
        }
    }
    for(int i=0;i<4;i++)
    {
        v1[i]=temp[i];
    }
    return v1;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a;
        ch=work(a);
        ch.resize(4);
        while(ch.size()>1&&ch.back()==0) ch.pop_back();
        for(int i=ch.size()-1;i>=0;i--)
        {
            cout<<ch[i];
        }
    }
}