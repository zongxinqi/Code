/*程序功能：猜出随机数number的值
  编程者  ：小淇
  日期    ：2017年9月26日21:43:30
  版本号  ：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#define MAX_NUMBER 100
#define MIN_NUMBER 1
#define MAX_TIMES 10
int MakeNumber(void);
void GuessNumber(const int number);
int IsValidNum(const int number);
int IsRight(const int number,const int guess);


int main()
{
	int number;            /*计算机生成的随机数*/
	char reply;            //用户对于是否继续做出的回答
	srand(time(NULL));     // 初始化随机种子
	do{
		number=MakeNumber();//计算机随机生成一个数 
		GuessNumber(number);//用户猜的数字
		printf("Do you want to countie(Y/N or y/n)");//提示是否继续
		scanf(" %c",&reply);//前面加一个空格，用于吃掉前面输入时存入缓冲区的回车 
	}while (reply=='Y'||reply=='y');//输入Y y时循环继续
	return 0; 
}


/*函数功能：计算机生成一个随机数
  函数参数：无
  函数返回值：返回计算机生成的随机数
*/
int MakeNumber(void)
{
    int number;
	number=(rand()%(MAX_NUMBER-MIN_NUMBER+1))+MIN_NUMBER;
	assert(number>=MIN_NUMBER&&number<=MAX_NUMBER);//判断生成的随机数是否符合要求 
	return number;	
}

/*函数功能：用户猜数字
  函数参数：number
  函数返回值：无
*/
void GuessNumber(const int number)
{
    int guess;//用户猜的数
	int count=0;//计数变量
	int right=0;//猜的结果正确与否
	int ret;//记录scanf（）的返回值，即读入的数据项数
	do{
		printf("Try %d:",count+1);
		ret=scanf("%d",&guess);
		//处理用户输入，判断是否有输入错误，是否在合法的输入范围之内
		while (ret!=1||!IsValidNum(guess))
		{
			printf("Input data error!\n");
			while(getchar()!='\n');//清楚输入缓冲区的错误数据
			printf("Try %d:",count+1);
			ret=scanf("%d",&guess); 
		 } 
		 count++;
		 right=IsRight(number,guess);//判断用户猜的数是大还是小 
	} while (!right&&count<MAX_TIMES);
	if (right)
	printf("Congratulations!\n");
	else
	printf("Mission failed after %d attempts\n",MAX_TIMES);
}
    

/*函数功能：判断用户输入是否在合法的数值范围之内
  函数参数：number
  函数返回值：1，0
*/
int IsValidNum(const int number)
 {
 	if(number>=MIN_NUMBER&&number<=MAX_NUMBER)
 	    return 1;
 	else 
 	    return 0;
 }
 
 
 /*函数功能：判断guess和number的大小关系
   函数参数：number,guess
   函数返回值：猜对了返回1，否则返回0
*/
int IsRight(const int number,const int guess)
{
	if(guess<number)
	{
		printf("Wrong! Too small!\n");
		return 0;
	}
	else if(guess>number)
	{
		printf("Wrong! Too big!\n");
		return 0;
	}
	else 
	    return 1;
}
