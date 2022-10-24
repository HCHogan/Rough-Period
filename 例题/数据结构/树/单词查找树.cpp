#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
string words[10001];
int n=1;
int main()
{
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    while(cin>>words[n]) n++;
    n--;
    sort(words+1,words+n+1); //按照字典顺序排列
    int sum = words[1].length();
    for(int i = 2;i<=n;i++)
    {
        int j;
        for(j=0;j<words[i-1].length(),j++)
        {
            if(words[i][j]!=words[i-1][j]) break;
        }
        sum+=words[i].length()-j;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
