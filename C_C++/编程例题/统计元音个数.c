#include<stdio.h>
#include<string.h>
int main()
{
	int j,n,len,a,e,i,o,u,count = 0;
	char c[100];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n--)
		{
			gets(c);
			len = strlen(c);
			a = e = i = o = u = 0;
			for(j = 0;j < len;j++)
			{
				if(c[j] == 'a') a++;
				else if(c[j] == 'e') e++;
				else if(c[j] == 'i') i++;
				else if(c[j] == 'o') o++;
				else if(c[j] == 'u') u++;
			}
			count++;
			if(count != 1) printf("\n");
			printf("a:%d\n",a);
			printf("e:%d\n",e);
			printf("i:%d\n",i);
			printf("o:%d\n",o);
			printf("u:%d\n",u);
		}
	}
	return 0;
}
