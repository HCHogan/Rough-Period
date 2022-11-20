#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

char t[N],s[N];
int n;

int main()
{
    cin>>n;
    scanf("%s",t+1);
    int cnt=1,idx=1,hh=0;
    for(int i=1;i<=n+1;i++)
    {
        if(i>cnt)
        {
            s[++hh]=t[i-1];
            idx++;
            cnt=(idx+1)*idx/2;
        }
        else continue;
    }
    for(int i=1;i<=hh;i++) cout<<s[i];
    cout<<endl;
    return 0;
}