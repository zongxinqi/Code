#include<stdio.h>
int main()
{
	const double PI=3.14159;
	double r,c,s;
	printf("input r:");
	scanf("%lf",&r);
	c=2*PI*r;
	s=PI*r*r;
	printf("printf WITHOUT width or  precision specifications:\n");
	printf("c=%f,s=%f\n",c,s);
	printf("printf WITH width and precision specifications:\n");
	printf("c=%7.2f,s=%7.2f\n",c,s); /*程序的第11行没有使用域宽和精度说明符即按%f格式输出实型数据，这时除非特别指定，否则隐含输出6位小数。程序13行，使用域宽和精度
	说明符即按%7.2格式输出实型数据，这里的%7.2%表示输出数据所占的域宽显示的精度是2.显示精度是指小数保留的位数。输出域宽为7是指输出数据占7哥字符宽度。注意，小数点
	也占一个字符位置。因此输出的小数之前会有两个空格。*/ 
 } 
