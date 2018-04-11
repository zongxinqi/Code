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
	srand((unsigned)time(NULL));/*srand(seed)前者是通过输入不同的数字来定义种子的数值，
	后者则是通过时间的变化来定义，NUll使time函数不具备显示时间的功能，只是给种子赋予了不同的值*/ 
do{
	magic=rand()%100+1;/*对100取余，可以是0到99之间的数，再加一则是1到100*/ 
    counter=0;/*计数变量*/ 
	do{
		printf("please guess a magic number :");
		ret=scanf("%d",&guess);
		while(ret!=1)/*若存在输入错误（若为假，执行下面的语句），则重新输入*/
		{while (getchar()!='\n');/*清除输入缓冲区的非法字符*/ 
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
		} while(guess!=magic&&counter<5);/*要是限制猜的次数，&&counter<n*/ 
	printf("%d\n",counter);
	printf("do you want to continue(Y/N or y/n)?\n");
	scanf(" %c",&reply);/*从scanf的实现机制来看，是由于在第一个输入之后必然会有一个空格，这些会在输入结
	束后压栈储存，于是在第二次输入时，会直接调用栈内的存储值，可能是空格回车tab，但一定不会是你输入的值*/
 }while((reply=='Y')||(reply=='y'));
	return 0;
 } 
