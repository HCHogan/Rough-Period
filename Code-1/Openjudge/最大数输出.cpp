#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c,d,e;
    scanf("%d%d%d",&a,&b,&c);
    d=max(a,b);
    e=max(d,c);
    printf("%d",e);
}