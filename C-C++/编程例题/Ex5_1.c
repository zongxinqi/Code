#include<stdio.h>
int main() 
{
	int m,n,i,p,q,x,c;
	printf("please input m,n:");
	scanf("%d,%d",&m,&n);
	for(i=1;i<=m;i++)
	{if(m%i==0)
	{p=n%i;
	if(p==0)
	q=i;/*ѭ���Ĺ��̾��Ǵ�1��ʼ�ҹ�Լ�������������󣬽�ֵ����q����������q��Ϊ���Լ��*/
	}
	}
	for(x=m;x<=m*n;x++)
	{
	if(x%m==0)
	{
		if(x%n==0)/*��С�������ض����ڵ�������һ��������С�ڵ����������ĳ˻�����x�����m,nȡ�඼Ϊ0ʱ��
		����������������ѭ�������x*/ 
		break;
	}	
	}
	printf("m,n�����Լ��=%d\n��С������=%d\n",q,x);
	return 0;
}
