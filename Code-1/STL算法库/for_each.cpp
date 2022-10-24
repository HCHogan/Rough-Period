#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class print{
public:
    void operator()(int val)
    {
        val+=100;
        cout<<val<<" ";
    }
};

class sb{
public:
    int operator()(int val)
    {
        return val+100;
    }
};

int main(){
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),sb());
    for_each(v.begin(),v.end(),print());
}