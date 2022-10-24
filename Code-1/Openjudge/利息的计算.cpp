#include<iostream>
using namespace std;
int main(){
    float r,m,y,sun,i,R;
    cin>>r>>m>>y;
    sun=m;
    R=1+r*0.01;
    for(i=0;i<y;i++){
        sun=sun*R;
    }
    printf("%ld",long(sun));
}