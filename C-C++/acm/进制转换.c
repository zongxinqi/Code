#include<stdio.h>
int main()
{
	int n,r,num[100],i,j,flag;
	char b[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while(scanf("%d%d",&n,&r)!=EOF&&r >= 2&&r <= 16)
	{
		i = 0;
		flag = 0;
		if(n < 0)
		{
			n = -1*n;
			flag = 1;
		}
			while(n!=0)
			{
				num[i] = n%r;
				n = n/r;
				i++;
			}
		if(flag) printf("-");
		for(j = i-1;j >= 0;j--)
		printf("%c",b[num[j]]);
		printf("\n");
	}
	return 0;
}
