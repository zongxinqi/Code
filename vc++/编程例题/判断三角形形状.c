#include <stdio.h>
#include <math.h>
#define EPS 1e-1
int main()
{
	float a,b,c;
	int flag=1;  /*�ñ�־����flagΪ��0ֵ*/
	printf("input a,b,c:");
	scanf("%f,%f,%f",&a,&b,&c) ;
	if(a+b>c&&b+c>a&&a+c>b)
	{
		if(fabs(a-b)<=EPS||fabs(b-c)<=EPS||fabs(c-a)<=EPS)
		{
        printf("����")��
		flag=0;
		 }
		 if(fabs(a*a+b*b-c*c)<EPS||fabs(a*a+c*c-b*b)<=EPS||fabs(b*b+c*c-a*a)<=EPS)
		 {
		 	printf("ֱ��")��
			flag=0; 
		 	}
		 	if(flag)  /*����־����flag��0������һ��������*/
		 	{
			printf("һ��") ��
			}
			printf("������\n") ;
		}
		else
		{
			printf("����������\n")
		}
}
