#include<stdio.h>
long fact(int n);/*�׳˵ĺ�����ʽ*/
int main()
{int m;
long ret;
do
{printf("please input m:");
scanf("%d",&m);
ret =fact(m);
/*if(ret==0);else*//*do while���������ж������ֵ�����Ϊ�������������룬��if�������жϷ���ֵ����Ϊ0�������
�������ݴ���Ϊ��������*/
} 
while(m<0);
printf("%d!=%ld\n",m,ret);
return 0;	
}
long fact (int n)
{
	int i;
	long result=1;
	if(n<0)
	{
		printf("input data error!\n");
	}
	else
{for(i=2;i<=n;i++)
	{
		result=result*i;
	}
		return result;/*�����mΪ����ʱ��result�Ľ����Ϊ��ֵ1*/ 
	}	

}
