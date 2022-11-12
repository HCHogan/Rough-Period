#include<iostream>
using namespace std;
const int N=100100,INF=0x3f3f3f3f;

int cntr,cntp;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        if(cntp>=cntr) printf("P\n");
        else printf("S\n");
        fflush(stdout);
        char c;
        cin>>c;
        if(c=='P') cntp++;
        if(c=='R') cntr++;
    }
    return 0;
}