#include<stdio.h>
void date(int a,int b,int c,int day[2][12]);
int main()
{
	int a,b,c;
	int day[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
	printf("please input a,b,c:");
	scanf("%d-%d-%d",&a,&b,&c);
	date(a,b,c,day);
	return 0;
}
void date(int a,int b,int c,int day[2][12])
{
	if(a>9999||a<1000)
	printf("a is wrong!\n");
	else
	{
	if(b<1||b>12)
	printf("b is wrong!\n");
	else
	{
	if(a%4==0&&a%100!=0||a%400==0)
	{
		if(b==2)
		{
			if(c>29||c<1)
			printf("c is wrong!");
			else
			printf("%d-%d-%d\n",a,b,c);
		}
		else
		{
			if(c>day[1][b-1]||c<1)
			printf("c is wrong!");
			else
			printf("%d-%d-%d\n",a,b,c);
		}
	}
	else
	{
		if(c>day[0][b-1]||c<1)
		printf("c is wrong!");
		else
		printf("%d-%d-%d\n",a,b,c);
	}
}
}
}
