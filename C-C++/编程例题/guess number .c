#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int magic,guess,counter,ret;
	char reply;
	unsigned int seed;
	printf("please enter seed:");
	scanf("%u",&seed);
	srand((unsigned)time(NULL));/*srand(seed)ǰ����ͨ�����벻ͬ���������������ӵ���ֵ��
	��������ͨ��ʱ��ı仯�����壬NUllʹtime�������߱���ʾʱ��Ĺ��ܣ�ֻ�Ǹ����Ӹ����˲�ͬ��ֵ*/ 
do{
	magic=rand()%100+1;/*��100ȡ�࣬������0��99֮��������ټ�һ����1��100*/ 
    counter=0;/*��������*/ 
	do{
		printf("please guess a magic number :");
		ret=scanf("%d",&guess);
		while(ret!=1)/*���������������Ϊ�٣�ִ���������䣩������������*/
		{while (getchar()!='\n');/*������뻺�����ķǷ��ַ�*/ 
		printf("please guess a number:");
		ret=scanf("%d",&guess);
		}
		counter++;
		if(guess>magic)
		printf("too big!\n");
		else if (guess<magic)
		printf("too small\n");
		else 
		printf("right!the number is %d\n",guess);
		} while(guess!=magic&&counter<5);/*Ҫ�����ƲµĴ�����&&counter<n*/ 
	printf("%d\n",counter);
	printf("do you want to continue(Y/N or y/n)?\n");
	scanf(" %c",&reply);/*��scanf��ʵ�ֻ����������������ڵ�һ������֮���Ȼ����һ���ո���Щ���������
	����ѹջ���棬�����ڵڶ�������ʱ����ֱ�ӵ���ջ�ڵĴ洢ֵ�������ǿո�س�tab����һ���������������ֵ*/
 }while((reply=='Y')||(reply=='y'));
	return 0;
 } 
