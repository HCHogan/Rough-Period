#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++)
    {
        for(int j=1;j<=2*n-1;j++)
        {
            if(j==n+1-i||j==9-n+i||j==n-9+i||j==19-n-i) printf("*");
            else printf(" ");
            printf(" ");
        }
        printf("\n");
    }
}