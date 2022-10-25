#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;

int v[5]={0,10,20,50,100};
int n,f[N];

int main()
{
    cin>>n;
    
    f[0]=1;
    for(int i=1;i<=4;i++)
        for(int j=v[i];j<=n;j++)
            f[j]+=f[j-v[i]];
            
    cout<<f[n]<<endl;
    
    return 0;
}

