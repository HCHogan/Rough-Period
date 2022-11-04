#include<stdio.h>
#include<cstdlib>
#include<stdbool.h>
#include<ctime>
int a,min=1,max=100;
int n;
bool flag=false;
void makeNum()
{
    srand((unsigned)time(NULL));
    a=rand()%100+1;
}
void guessNum()
{
    printf("请输入一个在%d到%d之间的数字:\n",min,max);
    scanf("%d",&n);
    if(n>a) {printf("大了\n");}
    if(n<a) {printf("小了\n");}
    if(n==a) {flag=true;printf("猜对了\n");}
    if(n<a&&n>min){min=n;}
    if(a<n&&n<max){max=n;}
}

int main()
{
    makeNum();
    guessNum();
    while(!flag)
    {
        guessNum();
    }
    if(flag) return 0;
}