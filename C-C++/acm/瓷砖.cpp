#include<stdio.h>
int main()
{
	int m[11],n;
	while(scanf("%d",&n) != EOF)
	{
		m[1] = 1;
		m[2] = 2;
		for(int i = 3;i <= n;i++)
		{
			m[i] = m[i-1] + m[i-2];
		}
		printf("%d\n",m[n]);
	}
	return 0;
}
