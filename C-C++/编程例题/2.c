 #include <stdio.h>
int main ()
{
	int a,b;
	scanf("%2d%*2d%2d",&a,&b);/*格式说明符%*2d炜忽略输入修饰符，表示对应的输入项在读入后步赋给相应的变量，%2d炜域宽附加格式说明，表示从输入数据中按规定宽度2从输
	入缓冲区中截取输入数据*/ 
	printf("a=%d\nb=%d\n",a,b);
} 
 
