#include<stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0,e=0;
	char ch;
	while((ch=getchar())!='\n')/*当输入的字符不是回车时，执行循环，取得输入字符的ASCII码*/
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
	printf("小写字母有%d个\n大写字母有%d个\n数字有%d个\n空格有%d个\n其他字符有%d个",a,b,c,d,e);
	return 0;
}
