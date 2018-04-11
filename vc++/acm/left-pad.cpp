#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char c;
	scanf("%d %c",&n,&c);
	char s[40000];
	getchar();
	gets(s);
	if(n >= strlen(s))
	{
		for(int i = 0;i < n - strlen(s);i++)
		printf("%c",c);
		for(int i = 0;i < strlen(s);i++)
		printf("%c",s[i]);
	}
	else 
	{
		for(int i = strlen(s) - n;i < strlen(s);i++)
		printf("%c",s[i]);
	}
	return 0;
}
