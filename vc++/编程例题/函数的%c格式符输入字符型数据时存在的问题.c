#include<stdio.h>
int main ()
{
	int data1,data2;
	char op;
	printf("please enter the expression data1+data2\n");
	scanf("%d%c%d",&data1,&op,&data2);
	printf("%d%c%d=%d\n",data1,op,data2,data1+data2);/*����%c��ʽ�����ַ�ʱ���ո��ַ���ת���ַ��������س������ᱻ������Ч�ַ����롣*/ 
}
