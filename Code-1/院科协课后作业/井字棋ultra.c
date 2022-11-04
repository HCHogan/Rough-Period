#include<stdio.h>
#include<stdbool.h>
char a[3][3]={'-','-','-','-','-','-','-','-','-'};
bool flag;
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
    int x,y;
    int m=0;
    print();
    while(scanf("%d %d",&x,&y))
    {
        if(m%2==1){ch='O';}
        if(m%2==0){ch='X';}
        if(a[x-1][y-1]=='-') a[x-1][y-1]=ch;
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
    }
}