#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int a[300], n, p, y, z, i=0, m, count = 0, j = 0,T,x;
    while(scanf("%d%d%d",&n,&p,&m),n||p||m)
    {
        memset(a, 1, sizeof a);
        count = n;
        while (count)
        {
            for (i = 0; i < n; i++)
            {
                x = (i + p-1)%n;
                if (a[i])
                {
                    j++;
                    if (j == m)
                    {
                        a[i] = 0;
                        cout << (i +p-1)%n+1;
                        if(count>1) cout<<",";
                        count--;
                        j = 0;
                    }
                }
            }
            cout<<endl;
        }
    }
}