#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double a,j,sum;
    char m;
    scanf("%lf %c",&a,&m);
    if(m=='y') 
        j=5;
    else j=0;
    if(a<=1000)
        sum=j+8;
    if(a>1000)
        sum=4*ceil((a-1000)/500)+j+8;
    printf("%.0lf",sum);
}