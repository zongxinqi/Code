#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d,s;
	printf("please input a,b,c:",&a,&b,&c);
	scanf("%f,%f,%f",&a,&b,&c);
	if(a+b>c&&a+c>b&&b+c>a) /*����֮�ʹ��ڵ����ߵ���ȷ�����Ҫ��������*/ 
	{
	d=(a+b+c)/2;
	s=(float)sqrt(d*(d-a)*(d-b)*(d-c));/*�����ؾ��ѹ�ʽ*/ 
	printf("s=%f\n",s);
	return 0;	
	}
	else
	{
		printf("���ܹ���������\n");
	}
}
