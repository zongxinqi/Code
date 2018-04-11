#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000003],b;
	int count,i;
	while(scanf("%s %c",&a,&b)!=EOF)
	{
		count = 0;
		for(i = 0;i < strlen(a);i++)
		{
			if(a[i] == b)count++;
		} 
		printf("%d\n",count);
	}
	return 0;
}
