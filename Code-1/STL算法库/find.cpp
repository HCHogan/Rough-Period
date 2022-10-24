#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main(){
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it=find(v.begin(),v.end(),11);
    if(it==v.end())
    {
        cout<<"未找到!"<<endl;
    }
    else
    {
        cout<<*it;
    }
}