
#include<stdio.h>
#include<string.h>
#define N 5
#define MAX_LEN 20
void sortstring(char *p[N]);
int main()
{
	int i,n;
	char string[N][MAX_LEN],*p[N];
	for(i=0;i<5;i++)
	{
		p[i]=string[i];
		gets(p[i]);
	}
	sortstring(p);
	for(i=0;i<5;i++)
	{
		puts(p[i]);
	}
	return 0;
}
void sortstring(char *p[N])
{
	int i,j;
	char *temp;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{if(strcmp(p[j],p[i])>0) 
		    {
			temp=p[i];
		    p[i]=p[j];
		    p[j]=temp;
			}
		} 
	}
}
