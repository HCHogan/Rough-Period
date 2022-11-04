#include<iostream>
using namespace std;
int main()
{
    string words[10001];
    int n=1;
    while(cin>>words[n])
    {
        n++;
    }
    n--;
    int sum=words[1].length();
    for(int i=2;i<=n;i++)
    {
        int j;
        for(j=0;j<words[i].length();j++)
        {
            if(words[i][j]!=words[i-1][j]) break;
        }
        sum+=words[i].length()-j;
    }
    cout<<sum;
}