#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int a[10]={1,3,3,3,4,4,4,8};
    int *lpos, *upos;
    lpos=lower_bound(a,a+9+1,-1);    //lower_bound(start,last,n)  :返回第一个大于等于n的地址
                                     //upper_bound(start,last,n)  :返回第一个大于n的地址
    upos=upper_bound(a,a+9+1,-1);    

    cout<<lpos<<" "<<upos<<endl;
    cout<<lpos-a<<" "<<upos-a<<endl;
    
    lpos=lower_bound(a,a+10,1);
    upos=upper_bound(a,a+10,1);
    cout<<lpos-a<<" "<<upos-a<<endl;

    lpos=lower_bound(a,a+10,3);
    upos=upper_bound(a,a+10,3);
    cout<<lpos-a<<" "<<upos-a<<endl;
    return 0;
}