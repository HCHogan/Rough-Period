#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
char a[3][3]={'-','-','-','-','-','-','-','-','-'};
bool flag;
int x,y;
char ch;
void print()
{
    printf("\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}

void create()
{
    x=rand()%3+1;
    y=rand()%3+1;
}
void isWin()
{
    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]) {flag=true;ch=a[0][0];}
    else if(a[0][0]==a[0][1]&&a[0][1]==a[0][2]) {flag=true;ch=a[0][0];}
    else if(a[1][0]==a[1][1]&&a[1][1]==a[1][2]) {flag=true;ch=a[2][0];}
    else if(a[2][0]==a[2][1]&&a[2][1]==a[2][2]) {flag=true;ch=a[2][0];}
    else if(a[0][0]==a[1][0]&&a[1][0]==a[2][0]) {flag=true;ch=a[0][0];}
    else if(a[0][1]==a[1][1]&&a[1][1]==a[2][1]) {flag=true;ch=a[0][2];}
    else if(a[0][2]==a[1][2]&&a[1][2]==a[2][2]) {flag=true;ch=a[0][2];}
    else if(a[2][0]==a[1][1]&&a[1][1]==a[0][2]) {flag=true;ch=a[2][0];}
}
int main()
{
    int m=0;
    print();
    while(scanf("%d %d",&x,&y))
    {
        if(a[x-1][y-1]=='-') a[x-1][y-1]='X';
        else {printf("输入有误");print();continue;}
        m++;
        print();
        isWin();
        if(ch=='-'){flag=false;}
        if(flag)
        {
            printf("%c胜利",ch);
            break;
        }
        if(m==9)
        {
            printf("平局");
            break;
        }
        create();
        while(a[ x-1][y-1]!='-'){create();}
        m++;
        a[x-1][y-1]='O';
        printf("等待对方下子");
        print();
        isWin();
        if(ch=='-'){flag=false;}
        if(flag)
        {
            printf("%c胜利",ch);
            break;
        }
        if(m==9)
        {
            printf("平局");
            break;
        }
    }
}