#include<iostream>
using namespace std;
int Judge(string a,float b,int c){
    if(b>=37.5&&c==1) return 1;
    else return 0;
}
int main(){
    int n,c[200],count=0;
    string a[200];
    float b[200];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        if(Judge(a[i],b[i],c[i])){
            printf("%s\n",a[i].c_str());
            count++;
        }
    }
    cout<<count;
    }