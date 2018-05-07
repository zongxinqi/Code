#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define SIZE 100
#define INF 999999999

int m[SIZE];		//存放矩阵链的行列信息，m[i-1]和m[i]分别为第i个矩阵的行和列（i = 1、2、3...）
int d[SIZE][SIZE];	//存放矩阵链计算的最优值，d[i][j]为第i个矩阵到第j个矩阵的矩阵链的最优值，i > 0

int Best_DP(int n)
{
	//把d[i][i]置为0，1 <= i < n
	memset(d, 0, sizeof(d));

	int len;
	//递归计算矩阵链的连乘最优值
	//len = 1，代表矩阵链由两个矩阵构成
	for (len = 1; len < n; len++)
	{
		int i, j, k;
		for (i = 1, j = i+len; j < n; i++, j++)
		{
			int min = INF; //无穷大
			for (k = i; k < j; k++)
			{
				int count = d[i][k] + d[k+1][j] + m[i-1] * m[k] * m[j];
				if (count < min)
				{
					min = count;
				}
			}
			d[i][j] = min;
		}
	}
	return d[1][n-1];
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &m[i]);
		}

		printf("%d\n", Best_DP(n));
	}
	return 0;
}
