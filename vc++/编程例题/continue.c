#include<stdio.h>
int main()
{
	int i,n;
	for(i=1;i<=3;i++)
	{
		printf("please input a number:");
		scanf("%d",&n);
		if(n<0)
		continue;/*�����ϵĻ����ڼ����������䣬���Ƿ���ִ��ǰ���ֱ��ѭ���ﵽ��������*/
		printf("n=%d\n",n);
	}
	printf("program is over!");
	return 0;
}
