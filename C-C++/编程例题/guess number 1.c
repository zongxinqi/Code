#include<stdio.h>
#include<stdlib.h>/*调用新的库函数*/
int main()
{
	int magic;
	int guess;
    magic=rand()%100+1;/*从数据库中任取一个1~100之间的数*/ 
    printf("please guess a magic number: ");
    scanf("%d",&guess);
    if(guess>magic)
    printf("too big!\n");
    else if(guess<magic)
    printf("too small!\n");
    else 
    printf("right!guess=%d\n",guess);
}
