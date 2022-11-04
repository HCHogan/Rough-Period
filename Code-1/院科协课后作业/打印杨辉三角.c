#include<stdio.h>
int main()
{
    int a[6][6];
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(j==0||j==i) a[i][j]=1;
            else
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
}