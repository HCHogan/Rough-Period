#include<iostream>//4121
using namespace std;
#include<vector>
int work(int n,int x)
{
    if(n==1) {return x;}
    else if(n%2==1) return (x*work(n-1,x))%10000;
    else{
        long int num=x*x;
        int cnt=num%10000;
        return work(n/2,cnt);
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        int ans;
        ans=work(x,2011);
        ans%=10000;
        vector<int> v;
        int g=1;
        for(int i=0;i<4;i++)
        {
            int temp=(ans/g)%10;
            g*=10;
            v.push_back(temp);
        }
        while(v.size()>0&&v.back()==0){v.pop_back();}
        for(int i=v.size()-1;i>=0;i--)
        {
            cout<<v[i];
        }
        cout<<endl;
    }
}