#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,len,flag;
	char c[100];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n--)
		{
			gets(c);
			len = strlen(c);
			flag = 1;
			if(len == 2) {
				if(c[0]!=c[1]) flag = 0;
			}
			else
			{	
				for(i = 0,j = len-1;i < len/2,j > len/2;i++,j--)
				{
					if(c[i]!=c[j]) 
					{
						flag = 0;
						break;
					}
				}
			}
		if(flag == 1) printf("yes\n");
		else printf("no\n");
		}
	}
	return 0;
}
