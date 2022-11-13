#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[10]={2,4,6,8,10,12,14,16,18,20};
    printf("逆序前\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n逆序后\n");
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",a[i]);
    }
    for(int i=n+m-2;i>=n-1;i--)
    {
        printf("%d ",a[i]);
    }
    for(int i=n+m-1;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}