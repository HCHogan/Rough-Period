#include<stdio.h>
int main()
{
    int a,b;
    for(int a=100;a<201;a++)
    {
        int cnt=0;
        for(int b=2;b*b<a;b++)
        {
            if(a%b==0) cnt++;
        }
        if(cnt==0) printf("%d\n",a);
    }
}