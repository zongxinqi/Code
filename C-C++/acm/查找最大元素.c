#include<stdio.h>
#include<string.h>
int main()
{
	int i,len;
	char c[100],max;
		while(gets(c))
		{
			len = strlen(c);
			max = c[0];
			for(i = 0;i < len;i++)
			{
				if(max < c[i]) max = c[i];
			}
			for(i = 0;i < len;i++)
			{
				if(max == c[i]) printf("%c(max)",c[i]);
				else printf("%c",c[i]);
			}
			printf("\n");
		}
	return 0;
}
