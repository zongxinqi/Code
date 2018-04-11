#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 5 
typedef struct footballteam
{
	char name[max_len];
	int data[6];
}TEAM;


void readdata(TEAM t[15],int n);

void printfdata(TEAM t[15],int n);
int main()
{
	int n,i,j;
	TEAM t[15];
	printf("please input the number of the footballteams:");
	scanf("%d",&n);
	readdata(t,n);
	for(i = 0;i < n;i++)
	{
		printf("%s",t[i].name);
		for(j = 0;j < 6;j++)
		{
		printf("%d",t[i].data[j]);
		}
	}
	return 0;
	
}


void readdata(TEAM t[15],int n)
{
	int i,j;
	for(i = 0;i < n;i++)
	{
		printf("please input the name all win equ lose GF GA:");
		scanf("%s",t[i].name);
		for(j = 0;j < 6;j++)
		{
			scanf("%d",&t[i].data[j]);
		}
	}
}


void printfdata(TEAM t[15],int n)
{
	int i,j;
	for(i = 0;i < n;i++)
	{
		printf("%s",t[i].name);
		for(j = 0;j < 6;j++)
		{
		printf("%d",t[i].data[j]);
		}
	}
}

