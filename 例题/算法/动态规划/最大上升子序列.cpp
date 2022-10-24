#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int n;
int a[10001][3];    //0为原始数据 1为以这个数结尾的最大上升子序列元素数
int ans=1,is=0,ie=0;   //2为从哪个数过来的 ans是最大值
stack<int> stk;
int main()   //开始和结束
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        a[i][1]=1;
    }
    for(int i=2;i<=n;i++)
    {
        int maxlen=0,idx=0;
        for(int j=1;j<i;j++)
        {
            if(a[j][0]<=a[i][0]&&a[j][1]>maxlen)
            {
                maxlen=a[j][1];
                idx=j;
            }
        }
        if(maxlen)
        {
            a[i][1]=maxlen+1;
            a[i][2]=idx;
            if(ans<a[i][1])
            {
                ans=a[i][1];
                ie=i;
            }
        }
    }
    cout<<"max="<<ans;
    if(!ie)
    {
        cout<<a[ie][0]<<endl;
        return 0;
    }
    while(ie)
    {
        stk.push(a[ie][0]);
        ie=a[ie][2];
    }
    while(!stk.empty())
    {
        cout<<stk.top()<<endl;
        stk.pop();
    }
    return 0;
}

