#include<iostream>
using namespace std;
string a,b;
int cnt=0;
void work(int L,int R);

int main()
{
    cin>>a>>b;
    work(0,b.length()-1);
}


void work(int L,int R)
{
    if(L==R) {cout<<b[L];return;}
    int T;
    char ch=a[cnt++];
    for(int i=0;i<b.length();i++)
    {
        if(b[i]==ch)
        {
            T=i;
            break;
        }
    }
    work(L,T-1);
    work(T+1,R);
    cout<<b[T];
}
//abdec
//dbeac
//->debca