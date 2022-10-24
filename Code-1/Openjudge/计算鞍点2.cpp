#include<stdio.h>
int main()
{
	int arr[10][10] = { 0 };
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int max = arr[i][0];
		int col = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				col = j;
			}
		}
 
		//找到当前行的最大值,从而去判断是不是当前列的最小值
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][col] < max) //flag列的某一个元素小于max.则表示max不是当前列最小值 不满足条件
			{
				res = 1;
				break;
			}
		}
		if (res == 0)
		{
			count++;
			printf("%d %d %d\n", i + 1, col + 1, arr[i][col]);
		}
	}
	if (count == 0)
	{
		printf("not found\n");
	}
	
	return 0;
}

