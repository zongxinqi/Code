#include<stdio.h>
 main()
{
	char ch;
	ch=getchar();/*从键盘任意输入一个字符，判断输入字符的类型，getchar取对应字符的ascii码*/
	if(ch>='0'&&ch<='9') /*在输入字符时需要用''*/ 
{	printf("数字");} 
	else
	if(ch>='A'&&ch<='Z')
{printf(" 大写字母");} 
	else
	if(ch>='a'&&ch<='z')
{	printf("小写字母");} 
	else
	if(ch==' ')
{	printf("空格");} 
	else
{	printf("其他字符");} 
	return 0;
}
