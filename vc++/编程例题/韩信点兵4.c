#include<stdio.h>
int main()
{
	int x=1;
	do
	{
		x++;
	}while(!(x%5==1 && x%6==5 && x%7==4 && x%11==10));/*����Ϊ�棬����ִ�У�֪�����Ϻ���ķ��̣��ж�����
	Ϊ�٣�����ѭ��*/
	printf("x=%d\n",x);
	printf("program is over");
	return 0;
	
}
