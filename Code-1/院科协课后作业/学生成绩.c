#include<stdio.h>
struct stu{
    int id;
    int score;
};
int main()
{
    int n;
    printf("请输入学生个数:\n");
    scanf("%d",&n);
    struct stu s[n];
    printf("请输入%d个学生的学号和成绩\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&s[i].id,&s[i].score);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(s[j].score<s[j+1].score)
            {
                int temp=s[j].score;
                s[j].score=s[j+1].score;
                s[j+1].score=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",s[i].id,s[i].score);
    }
}