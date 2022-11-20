#include<iostream>
using namespace std;
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        string a;
        int n;
        cin>>a>>n;
        int len=a.length();
        while(n--)
        {
            for(int i=0;i<len-1;i++)
            {
                if(a[i]>a[i+1])
                {
                    for(int j=i;j<len-1;j++)
                    {
                        a[j]=a[j+1];
                    }
                    len--;
                    break;
                }
                if(i==len-2)
                {
                    len--;
                }
            }
        }
        for(int i=0;i<len;i++) cout<<a[i];
        cout<<endl;
    }
}