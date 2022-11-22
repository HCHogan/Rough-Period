#include<iostream>
#include<cstring>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

char str[N];

int tobeplused[N],slen;
int tobecalced[N];

int main()
{
    cout<<"输入字符串"<<endl;
    cin>>str;
    slen=strlen(str);
    int dlen=0,digitcnt=0;
    for(int i=0;i<slen;i++)
    {
        if(str[i]>57&&str[i]<48)
        {

        }
        else
        {
            tobecalced[digitcnt++]=str[i]-48;
        }
    }
}