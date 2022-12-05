#include<iostream>
#include<vector>
using namespace std;
const int N=10010;

int* p;
int* q;

void test01()
{
    p=allocator<int>().allocate(512,(int*)0);
    for(int i=0;i<512;i++)
    {
        *(p+i)=i;
    }
    allocator<int>().deallocate(p,512);
    q=allocator<int>().allocate(512,(int*)0);
    q[1]=2;
}

int main()
{
    test01();
    cout<<p[1]<<endl;
    return 0;
}