#include<stdio.h>
struct stu{
    int class_score[4];
}s[3];
int sum=0,n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d ",&s[i].class_score[j]);
            sum+=s[i].class_score[j];
        }
    }
    printf("%f\n",(double)sum/12);
    for(int i=0;i<4;i++)
    {
        printf("%d ",s[n].class_score[i]);
    }
}