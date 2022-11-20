#include<iostream>
#include<cmath>
using namespace std;
const int N=2000000;
int main()
{
    int n,k,m=-1e9,index;
    scanf("%d %d",&n,&k);
    int a[N];
    int head=1,tail=k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=head;i<=tail;i++)
    {
        if(m<a[i])
        {
            m=a[i];
            index=i;
        }
    }
    while(tail<=n)
    {
        if(index>head&&index<tail)
        {
            if(m<a[tail]) m=a[tail];
        }
        else{
            m=a[head];
            for(int i=head+1;i<=tail;i++)
            {
                if(m<a[i])
                {
                    m=a[i];
                    index=i;
                }
            }
        }
        cout<<m<<endl;
        head++,tail++;
    }
}