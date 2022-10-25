#include<iostream>
using namespace std;
int ans;
void work(int x,int pre)
{
    for(int i=2;i<=(x/i);i++)
    {
        if(x%i==0 && (x/i)>=pre && i>=pre)
        {
            ans++;
            work(x/i,i);
        }
    }
}
int main()
{
    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        work(x,2);
        cout<<ans<<endl;

    }
    return 0;
}