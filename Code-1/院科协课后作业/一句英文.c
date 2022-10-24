#include<stdio.h>
int main()
{
    int cap=0,incap=0,space=0,sym=0;
    char a[100];
    //scanf("%s",a);
    gets(a);
    for(int i=0;a[i]!='\0';i++)
    {
        //int cnt=(int)a[i];
        if(a[i]>='A'&&a[i]<='Z') cap++;
        else if(a[i]==' ') space++;
        else if(a[i]>='a'&&a[i]<='z') incap++;
        else sym++;
    }
    printf("大写字母个数为：%d\n",cap);
    printf("小写字母个数为：%d\n",incap);
    printf("空格数量为：%d\n",space);
    printf("标点个数为：%d\n",sym);
}