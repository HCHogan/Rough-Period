#include<iostream>
#include<ctime>
using namespace std;
const int N=2010;
int a[N];
int res[N];
int temp;
int ask(int x,int y)
{
    cout << "? " << x << " " << y << endl;
	int res;
    cin >> res;
	return res;
}
int main()
{
    srand((unsigned)time(NULL));
    int n,index=1;
    cin>>n;
    int num;
    if(n<=20) num=n*n;
    if(n>20) num=3*n;
    int x=1,y=2;
    while(num--)
    {
        int m;
        int temp=ask(x,y);
        if(temp!=n)
        {
            //x=rand()%n+1;
            //y=rand()%n+1;
            x++;
            y++;
            x%=n+1;
            y%=n+1;
        }
        else if(temp==n)
        {
            m=y;
            for(int i=1;i<=n;i++)
            {
                if(m!=i) res[i]=ask(i,m);
            }
            sort(res+1,res+n+1);
            for(int i=1;i<=n;i++)
            {
                if(res[i]!=i-1)
                {
                    printf("! %d %d",i,i-1);
                    return 0;
                }
            }
            return 0;
        }
    }
}