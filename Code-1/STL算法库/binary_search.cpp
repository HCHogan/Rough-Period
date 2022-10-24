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
    //v.push_back(9);必须是有序序列，O(n)=logn
    bool flag=binary_search(v.begin(),v.end(),7);
    if(flag)
    {
        cout<<"have"<<endl;
    }
    else{
        cout<<"not have"<<endl;
    }
}