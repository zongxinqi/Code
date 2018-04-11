#include<stdio.h>
 int main ()
 {
 	char ch;
 	printf("Press a key and then press Enter:");
 	ch=getchar(); /*从键盘输入一个字符，按回车键结束输入，该字符被存入变量ch*/
	ch=ch+32;  /*将大写字母转换为小写字母*/
	printf("%c,%d\n",ch,ch); /*分别输出变量Ch中的字符及其ASCII码值*/
    putchar('\n'); /*输出一个回车换行控制符*/
    
  }  
