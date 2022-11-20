#include<iostream>
using namespace std;
#include<algorithm>
#include<queue>
#include<vector>
typedef pair<int,int> PII;
using namespace std;
struct Node{
    int begin,end;
    bool operator< (const Node &a) const
    {
        if(a.begin==this->begin) {return this->end<a.end;}
        return this->begin<a.begin;
    }//从小到大排序，以当前的为基准
}node[1010];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>node[i].begin>>node[i].end;
    }
    sort(node+1,node+n+1);
    int left=0,ans=0;
    for(int i=0;i<n;i++)
    {
        priority_queue<PII,vector<PII>,greater<PII> > q;
        for(int j=i+1;j<=n;j++)
        {
            if(node[j].begin>=left) {
                q.push(make_pair(node[j].end,j));
            }
        }
        if(!q.empty())
        {
            left=q.top().first;
            i=q.top().second;//此处会修改i的值，如果队列定义在循环外，则top就乱了，死循环
            ans++;
        }
        else{//经过我反复的分析，他不可能空
            break;
        }
        //cout<<q.size();
    }
    cout<<ans;
    // while(!q.empty())
    // {
    //     cout<<q.top().second<<" ";
    //     q.pop();
    // }
}