#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int z[N],n,m,idx;
char str[N];

int get_z(char* str)
{
   z[1]=n;
   for(int i=2,l,r=0;str[i];i++)
   {
        if(i<=r) z[i]=min(z[i-l+1],r-i+1);
        while(str[1+z[i]]==str[i+z[i]]) z[i]++;
        if(1+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
   } 
}


int main()
{
    cin>>str+1;
    cin>>n;
    get_z(str);
    return 0;
}