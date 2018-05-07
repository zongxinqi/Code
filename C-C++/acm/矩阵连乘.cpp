#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define SIZE 100
#define INF 999999999

int m[SIZE];		//��ž�������������Ϣ��m[i-1]��m[i]�ֱ�Ϊ��i��������к��У�i = 1��2��3...��
int d[SIZE][SIZE];	//��ž��������������ֵ��d[i][j]Ϊ��i�����󵽵�j������ľ�����������ֵ��i > 0

int Best_DP(int n)
{
	//��d[i][i]��Ϊ0��1 <= i < n
	memset(d, 0, sizeof(d));

	int len;
	//�ݹ�������������������ֵ
	//len = 1��������������������󹹳�
	for (len = 1; len < n; len++)
	{
		int i, j, k;
		for (i = 1, j = i+len; j < n; i++, j++)
		{
			int min = INF; //�����
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
