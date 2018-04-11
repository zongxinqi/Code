#include<stdio.h>
#include<string.h>
int main()
{
	int n,a,b,c;
	char pad[50];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n--)
		{
			gets(pad);
			for(i = 0;i < strlen(pad);i++)
			{
				if(pad[i]) a++;
				else if(pad[i]) b++;
				else if(pad[i]) c++;
			}
			if(a > 0&&b > 0&&c > 0) printf("YES\n");
			else printf("NO\n");
		}
	}
}
