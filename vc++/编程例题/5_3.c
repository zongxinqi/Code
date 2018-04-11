#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d,s;
	printf("please input a,b,c:",&a,&b,&c);
	scanf("%f,%f,%f",&a,&b,&c);
	if(a+b>c&&a+c>b&&b+c>a) /*两边之和大于第三边的正确表达需要用且连接*/ 
	{
	d=(a+b+c)/2;
	s=(float)sqrt(d*(d-a)*(d-b)*(d-c));/*海伦秦九昭公式*/ 
	printf("s=%f\n",s);
	return 0;	
	}
	else
	{
		printf("不能构成三角形\n");
	}
}
