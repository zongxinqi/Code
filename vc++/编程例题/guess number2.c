/*�����ܣ��³������number��ֵ
  �����  ��С�
  ����    ��2017��9��26��21:43:30
  �汾��  ��
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
	int number;            /*��������ɵ������*/
	char reply;            //�û������Ƿ���������Ļش�
	srand(time(NULL));     // ��ʼ���������
	do{
		number=MakeNumber();//������������һ���� 
		GuessNumber(number);//�û��µ�����
		printf("Do you want to countie(Y/N or y/n)");//��ʾ�Ƿ����
		scanf(" %c",&reply);//ǰ���һ���ո����ڳԵ�ǰ������ʱ���뻺�����Ļس� 
	}while (reply=='Y'||reply=='y');//����Y yʱѭ������
	return 0; 
}


/*�������ܣ����������һ�������
  ������������
  ��������ֵ�����ؼ�������ɵ������
*/
int MakeNumber(void)
{
    int number;
	number=(rand()%(MAX_NUMBER-MIN_NUMBER+1))+MIN_NUMBER;
	assert(number>=MIN_NUMBER&&number<=MAX_NUMBER);//�ж����ɵ�������Ƿ����Ҫ�� 
	return number;	
}

/*�������ܣ��û�������
  ����������number
  ��������ֵ����
*/
void GuessNumber(const int number)
{
    int guess;//�û��µ���
	int count=0;//��������
	int right=0;//�µĽ����ȷ���
	int ret;//��¼scanf�����ķ���ֵ�����������������
	do{
		printf("Try %d:",count+1);
		ret=scanf("%d",&guess);
		//�����û����룬�ж��Ƿ�����������Ƿ��ںϷ������뷶Χ֮��
		while (ret!=1||!IsValidNum(guess))
		{
			printf("Input data error!\n");
			while(getchar()!='\n');//������뻺�����Ĵ�������
			printf("Try %d:",count+1);
			ret=scanf("%d",&guess); 
		 } 
		 count++;
		 right=IsRight(number,guess);//�ж��û��µ����Ǵ���С 
	} while (!right&&count<MAX_TIMES);
	if (right)
	printf("Congratulations!\n");
	else
	printf("Mission failed after %d attempts\n",MAX_TIMES);
}
    

/*�������ܣ��ж��û������Ƿ��ںϷ�����ֵ��Χ֮��
  ����������number
  ��������ֵ��1��0
*/
int IsValidNum(const int number)
 {
 	if(number>=MIN_NUMBER&&number<=MAX_NUMBER)
 	    return 1;
 	else 
 	    return 0;
 }
 
 
 /*�������ܣ��ж�guess��number�Ĵ�С��ϵ
   ����������number,guess
   ��������ֵ���¶��˷���1�����򷵻�0
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
