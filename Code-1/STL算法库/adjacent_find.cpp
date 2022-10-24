#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main(){
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    v.push_back(9);
    vector<int> ::iterator it = adjacent_find(v.begin(),v.end());
    cout<<*it;
    cout<<*(++it);
}