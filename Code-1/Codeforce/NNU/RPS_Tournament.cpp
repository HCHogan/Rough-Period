#include<iostream>
#include<ctime>
using namespace std;
char a[3]={'P','S','P'};
int main()
{
    srand((unsigned int)time(NULL));
    int k,score;
    cin>>k>>score;
    while(k--)
    {
        int t=rand()%3;
        cout<<a[t]<<endl;
        char c;
        cin>>c;
    }
}