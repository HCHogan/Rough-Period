//21220513杨圣涵
#include<iostream>
using namespace std;
const int N=100100,INF=0x3f3f3f3f;

char a[]={'P','P','S'};

int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        printf("%c\n",a[i%3]);
        fflush(stdout);
        char c;
        cin>>c;
    }
    return 0;
}