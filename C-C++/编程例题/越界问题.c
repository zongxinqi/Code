#include<stdio.h>
int main()
{
	int a=1,c=2,b[5]={0},i;
	printf("%p,%p,%p\n",&a,b,&c);
	for(i=0;i<=8;i++)
	{
		b[i]=i;
	   printf("%d\n",b[i]); 	
	}
	printf("%d,%d",a,c);
	return 0;/*����a��c��ֵ����ΪԽ��������ĸı���*/
}
