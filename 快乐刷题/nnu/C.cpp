#include<iostream>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;

int tempans[N],ans[N];
int n,sumof23;

int main()
{
    cin>>n;
    printf("? %d %d\n",2,3);
    fflush(stdout);
    scanf("%d",&sumof23);
    for(int i=2;i<=n;i++)
    {
        printf("? %d %d\n",1,i);
        fflush(stdout);
        scanf("%d",&tempans[i]);
    }
    ans[1]=tempans[3]-sumof23;
    tempans[1]=ans[1];
    for(int i=2;i<=n;i++)
    {
        ans[i]=tempans[i]-tempans[i-1];
    }
    cout<<"!";
    for(int i=1;i<=n;i++) cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}