#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*n-1;j++)
        {
            if(j>=n+1-i&&j<=n-1+i) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}