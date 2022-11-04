#include<stdio.h>
struct stu{
    int id;
    int score;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct stu s[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&s[i].id,&s[i].score);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
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