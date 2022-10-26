#include<stdio.h>
int main()
{
	int a[10] = { 7,87,9,5,3,5,6,86,4,56 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <10; j++)
		{
			if (a[i] > a[j])
			{
				int d = a[i];
				a[i] = a[j];
				a[j] = d;
			}
		}
	}
	for (int c = 0; c < 10; c++)
		printf("%d ",a[c]);
	return 0;
}