#include<stdio.h>
#include<stdlib.h>/*�����µĿ⺯��*/
int main()
{
	int magic;
	int guess;
    magic=rand()%100+1;/*�����ݿ�����ȡһ��1~100֮�����*/ 
    printf("please guess a magic number: ");
    scanf("%d",&guess);
    if(guess>magic)
    printf("too big!\n");
    else if(guess<magic)
    printf("too small!\n");
    else 
    printf("right!guess=%d\n",guess);
}
