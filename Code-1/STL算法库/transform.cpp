#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
class trans{
    public:
        int operator()(int val)
        {
            return 100+val;
        }
};

int main(){
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>v2;

    v2.resize(v.size());//不然会内存泄漏

    transform(v.begin(),v.end(),v2.begin(),trans());
    for(vector<int>::iterator it =v2.begin();it!=v2.end();it++)
    {
        cout<<*it<<" ";
    }
}