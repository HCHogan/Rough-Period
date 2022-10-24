
#include<cstdio>
int main()
{   double n;
    scanf("%lf",&n);
    if(n>=0&&n<5)
    printf("%.3f",2.5-n);
    else if(n>=5&&n<10)
    printf("%.3f",2-1.5*(n-3)*(n-3));
    else printf("%.3f",n/2-1.5);
    return 0;
}