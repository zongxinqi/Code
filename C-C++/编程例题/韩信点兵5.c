#include<stdio.h>
int main()
{
	int x=1;
	int find=0;
	do
	{
		x++;
	}while(find==(x%5==1 && x%6==5 && x%7==4 && x%11==10));/*find==0,�����Ϊ�����ѭ��������������ʱ��
	0��=1������Ϊ�٣�����ѭ��*/
	printf("x=%d\n",x);
 } 
