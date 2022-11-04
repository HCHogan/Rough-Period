#include<stdio.h>
#include<stdbool.h>
int main()
{
    char a[3][4];
    bool flag=false;
    char ch;
    int x=0,y=0,z=0;
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=3;j++)
        {
            scanf("%c",&a[i][j]);
            if(a[i][j]=='O'){x++;}
            if(a[i][j]=='X'){y++;}
            if(a[i][j]=='-'){z++;}
        }
        //getchar();
    }
    //printf("%d %d",x,y);
    if(x==y+1||x+1==y||x==y){
        if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]) {flag=true;ch=a[0][0];}
        if(a[0][0]==a[0][1]&&a[0][1]==a[0][2]) {flag=true;ch=a[0][0];}
        if(a[1][0]==a[1][1]&&a[1][1]==a[1][2]) {flag=true;ch=a[2][0];}
        if(a[2][0]==a[2][1]&&a[2][1]==a[2][2]) {flag=true;ch=a[2][0];}
        if(a[0][0]==a[1][0]&&a[1][0]==a[2][0]) {flag=true;ch=a[0][0];}
        if(a[0][1]==a[1][1]&&a[1][1]==a[2][1]) {flag=true;ch=a[0][2];}
        if(a[0][2]==a[1][2]&&a[1][2]==a[2][2]) {flag=true;ch=a[0][2];}
        if(a[2][0]==a[1][1]&&a[1][1]==a[0][2]) {flag=true;ch=a[2][0];}
        if(flag) printf("%c胜利!",ch);
        else{
            printf("平局！");
        }
        return 0;
    }
    else printf("输入有误！");return 0;
}