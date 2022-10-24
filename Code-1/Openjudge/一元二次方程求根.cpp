#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int main(){
    double a,b,c,x1,x2;
    scanf("%lf%lf%lf",&a,&b,&c);
    x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
    x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
    if(b*b<4*a*c&&b==0){
        printf("x1=0.00000+%.5lfi;x2=0.00000-%.5lfi\n",sqrt(-b*b+4*a*c)/(2*a),sqrt(-b*b+4*a*c)/(2*a));
    }
    if(b*b==4*a*c)
        printf("x1=x2=%.5lf\n",x1);
    if(b*b>4*a*c)
        printf("x1=%.5lf;x2=%.5lf\n",x1,x2);
    if(b*b<4*a*c&&b!=0)  
        printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",-b / (2*a),sqrt(-b*b+4*a*c)/(2*a),-b / (2*a),sqrt(4*a*c-b*b) / (2*a));
}
