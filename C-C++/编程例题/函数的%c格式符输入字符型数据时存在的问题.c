#include<stdio.h>
int main ()
{
	int data1,data2;
	char op;
	printf("please enter the expression data1+data2\n");
	scanf("%d%c%d",&data1,&op,&data2);
	printf("%d%c%d=%d\n",data1,op,data2,data1+data2);/*在用%c格式读入字符时，空格字符和转义字符（包括回车）都会被当作有效字符读入。*/ 
}
