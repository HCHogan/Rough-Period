#include<iostream>
using namespace std;

int ans;

void work(int a,int pre)
{
    for(int i=2;i<=a/i;i++)//一定要i<=a/i,等号不能少
    {
        if(a%i==0&&i>=pre)
        {
            ans++;//只要能进行到这一步，说明至少还有数可以分解，所以这个数不拆就是原来的情况，而拆了以后是一种新的情况，所以++。
            work(a/i,i);//也就是上一步可以理解为增加一个当前方法的分支
            //而比如当已经分出2*2时，函数终止；i++到4以后继续增加方法。
        }
    }
}


int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        ans=1;
        cin>>a;
        work(a,2);
        cout<<ans<<endl;
    }
}