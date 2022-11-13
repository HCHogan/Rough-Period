#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
const int N=50;
bool a[N];
int n;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    n=s1.length();
    for(int i=1;i<=n;i++){
        if(s1[i-1]==s2[i-1]){
            a[i]=1;
        }
        else{
            a[i]=0;
        }
    }
    // 储存是否相同
    a[0]=0;
    a[n+1]=0;
    // for(int i=0;i<=n+1;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int res=0;
    if(a[1]==0&&a[2]==0&&a[3]==0){
        res++;
        a[1]=1,a[2]=1,a[3]=1;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0&&a[i-1]==0){
            a[i-1]=1;
            a[i]=1;
            if(a[i+1]==0){
                a[i+1]=1;
            }
            else{
                a[i+1]=0;
            }
            res++;
        }
    }
    int flag=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<res;
    }
    else{
        cout<<"impossible";
    }
    return 0;

}