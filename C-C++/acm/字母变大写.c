#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,len;
	char s[100];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n--)
			gets(s);
			len = strlen(s);
		for(i = 0;i < len;i++)
		{
			s[0] = s[0] - 32;
			if(s[i] = ' ') s[i + 1]-=32;
			printf("%c1",s[i]);
		}
		printf("\n");
	}
	return 0;
}
