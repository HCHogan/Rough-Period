#include<stdio.h>
#include<stdlib.h>
#include"井字棋ultrapromax.c"
#include"井字棋ultra.c"
#include<time.h>
int num[100],con[17];
int n;
int x=0,y=0,z=0,d=0;
//char a[4];
void createNum()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++)
    {
        num[i]=rand()%9+1;
        //printf("%d",num[i]);
    }
    // for(int i=0;<4;i++)
    // {
    //     a[i]=num[i];
    // }
}

void punish1()
{
    printf("请联系部长玩真心话大冒险!");
}


void chess()
{
    int cnt;
    printf("1、双人模式\n2、人机模式(傻瓜版)\n");
    scanf("%d",&cnt);
    if(cnt==1) couple();
    else if(cnt==2) computer();
    else{printf("输入有误，请重续选择！");}
}


int main()
{
    int m=0;//输入有误的轮数
    int k=16;//游戏次数
    printf("请输入难度");
    scanf("%d",&n);
    createNum();
    int game=0;
    while(k--)
    {
        x=0,y=0,z=0;//输出值
        printf("请输入%d个数字: ",n);
        int book[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&book[i]);
        }
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(book[i]==num[i]) {x++;flag++;continue;}
            else{
                for(int j=0;j<n;j++)
                {
                    if(book[i]==num[j]&&i!=j) {y++;flag++;break;}
                }
            }
        }
        z+=n-flag;
        con[16-k]=x;
        printf("%dA%dB%dC\n",x,y,z);
        if(x==n) {game=1;break;}
        else{m++;}
        if(m==8||m==16)
        {
            //m=0;
            punish1();
        }
    }
    if(game==0) printf("愚蠢的凡人！");
    else if(game==1&&k>=13)
    {
        printf("玩井字棋吗？（别玩！！！）\n1、玩\n2、不玩\n");
        int in_put;
        scanf("%d",&in_put);
        if(in_put==2) {printf("游戏成功！");return 0;}
        else if(in_put==1) chess();
        else {printf("输入有误，请重续选择！");}
    }
    return 0;
}