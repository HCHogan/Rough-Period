#include<iostream>
#include<cmath>
using namespace std;
int m;//n为格子，m为液体
long int n;
int num;
const long N=10001000;
long sum=0;
int a[N];
void dfs(int x)
{
    if(x==n+1)
    {
        sum++;
        sum%=100003;
        return;
    }
    for(int i=1;i<=num;i++)
    {
        if(i!=a[x-1])
        {
            a[x]=i;
            dfs(x+1);
        }
    }
}

int fact(int x,int z)
{
    if(x==z) return x;
    return x*fact(x-1,z);
}
int main()
{
    scanf("%d %ld",&m,&n);
    long long total=pow(m,n);
    int s=m/n;
    if(s>=1) num=n;
    else num=m;
    dfs(1);
    if(m>n)
    {
        sum*=fact(m,n+1)/(fact(n,1));
    }
    total%=100003;
    sum%=100003;
    total-=sum;
    total%=100003;
    cout<<total<<endl;
}