#include<iostream>
using namespace std;
int main()
{
    int *pa=new int (1);
    int *pb=new int (2);
    int a=1;
    int b=1;
    cout<<&a<<endl<<&b<<endl;
    printf("%d\n",*(pa));
    printf("%d\n",*(pb));
    printf("%d\n",*(pb-4));       //堆区差4个 栈区紧靠
    cout<<sizeof(cout)<<endl;
    return 0;
}