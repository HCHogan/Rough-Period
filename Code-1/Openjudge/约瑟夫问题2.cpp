#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> v;
int main()
{
    int n,m,p,t;
    cin>>n>>p>>m;
    cin>>t>>t>>t;
    for(int i=0;i<n;i++)
    {
        v.push_back(i+1);
    }
    int index=p-1,cnt=0;
    while(!v.empty())
    {
        cnt++;
        if(cnt==m)
        {
            cout<<v[index];
            if(v.size()>1) cout<<",";
            v.erase(v.begin()+index);
            cnt=0;
        }
        else
        {
            index=(index+1)%v.size();
        }
    }
    cout<<endl;
    return 0;
} 