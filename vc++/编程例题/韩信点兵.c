#include<stdio.h>
int main()
{
	int x;
	for(x=1;;x++)
	{
		if(x%5==1&&x%6==5&&x%7==4&&x%11==10)
	{	printf("x=%d\n",x);
		break;/*���ҵ�һ�����ʵ����������ѭ����������Ӿͻ��������������������ѭ����*/
		}
	}
	printf("program is over");
	return 0;
}
