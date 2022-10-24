#include<iostream>
using namespace std;
int main(){
    float a[100],n;
    float e=0,b=0,c=0,d=0;
    float p1,p2,p3,p4;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0&&a[i]<=18) e++;
        if(a[i]>=19&&a[i]<=35) b++; 
        if(a[i]>=36&&a[i]<=60) c++;
        if(a[i]>=61) d++;
    }
    p1=e/n;
    p2=b/n;
    p3=c/n;
    p4=d/n;
    printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%\n",100*p1,100*p2,100*p3,100*p4);
}