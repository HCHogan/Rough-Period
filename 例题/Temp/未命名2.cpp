#include<iostream>
using namespace std;
int data[1001],n,max1=0;
int search (int i, int t, int a)
{
	int j;
	if (j=n) if (t>max1) max1=t;
	for(j=i;j<=n;j++)
	{
		if(data[j]>a)
		{
			t++;
			search(j,t,data[j]);
	    }
	}
	t--;
}
int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>data[i];
	}
	search(1,0,0);
	cout<<max1;
	return 0;
}
//hello,vim
