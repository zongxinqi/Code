#include<stdio.h>
 main()
{
	char ch;
	ch=getchar();/*�Ӽ�����������һ���ַ����ж������ַ������ͣ�getcharȡ��Ӧ�ַ���ascii��*/
	if(ch>='0'&&ch<='9') /*�������ַ�ʱ��Ҫ��''*/ 
{	printf("����");} 
	else
	if(ch>='A'&&ch<='Z')
{printf(" ��д��ĸ");} 
	else
	if(ch>='a'&&ch<='z')
{	printf("Сд��ĸ");} 
	else
	if(ch==' ')
{	printf("�ո�");} 
	else
{	printf("�����ַ�");} 
	return 0;
}
