#include<stdio.h>
int main()
{
	const double PI=3.14159;
	double r,c,s;
	printf("input r:");
	scanf("%lf",&r);
	c=2*PI*r;
	s=PI*r*r;
	printf("printf WITHOUT width or  precision specifications:\n");
	printf("c=%f,s=%f\n",c,s);
	printf("printf WITH width and precision specifications:\n");
	printf("c=%7.2f,s=%7.2f\n",c,s); /*����ĵ�11��û��ʹ�����;���˵��������%f��ʽ���ʵ�����ݣ���ʱ�����ر�ָ���������������6λС��������13�У�ʹ�����;���
	˵��������%7.2��ʽ���ʵ�����ݣ������%7.2%��ʾ���������ռ�������ʾ�ľ�����2.��ʾ������ָС��������λ����������Ϊ7��ָ�������ռ7���ַ���ȡ�ע�⣬С����
	Ҳռһ���ַ�λ�á���������С��֮ǰ���������ո�*/ 
 } 
