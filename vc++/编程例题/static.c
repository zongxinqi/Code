#include<stdio.h>
long Func(int n);
int main()
{
	int i,n;
	char c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("%d!=%d\n",i,Func(i));
	}
	return 0;
}
//�������ܣ�ͨ����̬����ʵ��n�Ľ׳˵���� 
long Func(int n)
{
	static long p=1;
	p=p*n;
	return p;
}
