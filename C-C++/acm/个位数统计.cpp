#include<stdio.h>
#include<string.h>
char num[1003];
int main()
{
	int ans[10];
	memset(ans,0,sizeof(ans));
	gets(num);
	for(int i = 0;i < strlen(num);i++)
	{
		for(int k = 48;k <= 57;k++)
		{
			if(num[i] == k) ans[k-48]++;
		}
	}
	for(int j = 0;j <= 9;j++)
	{
		if(ans[j] != 0) 
			printf("%d:%d\n",j,ans[j]);
	}
	return 0;
} 
