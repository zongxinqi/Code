#include <stdio.h>
int main()    /* const������� */ 
{
    const double PI=3.14159;  /*����ʵ�͵�const����  */ 
    double  r;
  	printf("Input r:");
	scanf("%lf",&r);
    printf("c=%f\n",4*PI*r*r);
	printf("s=%f\n",4.0/3*PI*r*r*r);
}                                     /* const�������������ͣ��������ܶ���������ͼ�� */ 
