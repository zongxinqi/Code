#include<stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0,e=0;
	char ch;
	while((ch=getchar())!='\n')/*��������ַ����ǻس�ʱ��ִ��ѭ����ȡ�������ַ���ASCII��*/
	{
		if(ch>='a'&&ch<='z')
		a++;
		else if(ch>='A'&&ch<='Z')
		b++;
		else if(ch>='0'&&ch<='9')
		c++;
		else if(ch==' ')
		d++;
		else
		e++;
	}
	printf("Сд��ĸ��%d��\n��д��ĸ��%d��\n������%d��\n�ո���%d��\n�����ַ���%d��",a,b,c,d,e);
	return 0;
}
