#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,flag,len;
	char c[50];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n--)
		{
			flag = 1;
			gets(c);
			len = strlen(c);
			for(i = 0;i < len;i++)
						{
							if(i == 0)
							{
								if(!(c[i] == '_'||(c[i] >= 'A'&& c[i] <= 'Z')||(c[i] >= 'a'&& c[i] <= 'z'))) 
								{
									flag = 0;
									break;
								}
							}
							else
							{
								if(!(c[i] == '_'||(c[i] >= 'A'&& c[i] <= 'Z')||(c[i] >= 'a'&& c[i] <= 'z')||(c[i] >= '0'&&c[i] <= '9')))
								{
									flag = 0;
									break;
								}
							}
							if((c[i] == 'i'&&c[i+1] == 'n'&&c[i+2] == 't')||(c[i] == 'b'&&c[i+1] == 'r'&&c[i+2] == 'e'&&c[i+3] == 'a'&&c[i + 4] == 'k'))
							{
								flag = 0;
								break;
							} 
						}
			if(flag == 0) printf("no\n");
			else printf("yes\n");
		}
	}
	return 0;
}
