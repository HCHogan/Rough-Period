#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int year(int a){
    if(a%4!=0||(a%100==0&&a%400!=0)) {return 0;}
    else return 1;
}

int main(){
    int Month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int MonthR[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int n,i,x,j;
    int Year[2]={365,366};
    cin>>n;
    x=n%7;
    string week[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    for(i=2000;n>=Year[year(i)];i++){
        n-=Year[year(i)];
    }
    if(year(i)==1){
        for(j=1;n>=MonthR[j];j++){
            n-=MonthR[j];
        }
    }
    if(year(i)==0){
        for(j=1;n>=Month[j];j++){
            n-=Month[j];
        }
    }
    cout<<i<<"-"<<setfill('0')<<setw(2)<<j<<"-"<<setfill('0')<<setw(2)<<n+1<<" "<<week[x];
}