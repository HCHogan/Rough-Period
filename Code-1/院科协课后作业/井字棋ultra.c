#include<stdio.h>
#include<stdbool.h>
char arr[3][3]={'-','-','-','-','-','-','-','-','-'};
bool flag;
char ch;
void print1()
{
    printf("\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}

void isWin1()
{
    if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]) {flag=true;ch=arr[0][0];}
    else if(arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2]) {flag=true;ch=arr[0][0];}
    else if(arr[1][0]==arr[1][1]&&arr[1][1]==arr[1][2]) {flag=true;ch=arr[2][0];}
    else if(arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2]) {flag=true;ch=arr[2][0];}
    else if(arr[0][0]==arr[1][0]&&arr[1][0]==arr[2][0]) {flag=true;ch=arr[0][0];}
    else if(arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1]) {flag=true;ch=arr[0][2];}
    else if(arr[0][2]==arr[1][2]&&arr[1][2]==arr[2][2]) {flag=true;ch=arr[0][2];}
    else if(arr[2][0]==arr[1][1]&&arr[1][1]==arr[0][2]) {flag=true;ch=arr[2][0];}
}
void couple()
{
    int x,y;
    int m=0;
    print1();
    while(scanf("%d %d",&x,&y))
    {
        if(m%2==1){ch='O';}
        if(m%2==0){ch='X';}
        if(arr[x-1][y-1]=='-') arr[x-1][y-1]=ch;
        else {printf("输入有误");print1();continue;}
        m++;
        print1();
        isWin1();
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

