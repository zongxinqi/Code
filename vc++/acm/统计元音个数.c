#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,len,a,e,i2,o,u,count;
	char c[100];
	while(scanf("%d",&n)!=EOF)
	{
		count = 0;
		getchar();
		while(n--)
		{
			gets(c); 
			len = strlen(c);
			a = e = i2 = o = u = 0;
			for(i = 0;i < len;i++)
			{
				if(c[i] == 'a') a++;
				else if(c[i] == 'e') e++;
				else if(c[i] == 'i') i++;
				else if(c[i] == 'o') o++;
				else if(c[i] == 'u') u++;
			}
			count++;
			if(count != 1) printf("\n");
			printf("a:%d\n",a);
			printf("e:%d\n",e);
			printf("i:%d\n",i2);
			printf("o:%d\n",o);
			printf("u:%d\n",u);
		}
	}
	return 0;
}
