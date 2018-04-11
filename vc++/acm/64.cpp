#include<stdio.h>
#include<string.h>
int main()
{
	char a[103];
	int i,count;
	while(scanf("%s",&a) != EOF)
	{
		count = 0;
		for(i = 0;i < strlen(a);i++)
		{
			if(a[i] == '1') 
			{
				for(int j = i;j <strlen(a);j++)
				{
					if(a[j] == '0') count++;
				}
				break;
			}
		}
		if(count >= 6) 
		printf("yes\n");
		else printf("no\n");
	}
	return 0;
 } 
