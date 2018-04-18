#include<stdio.h>
#include<math.h>
int main()
{
	int sign=1;
	double pi=0,term=1,n=1;
	while(fabs(term)>=1e-8)
	{
		pi=pi+term;
		n=n+2;
		sign=-sign;
		term=sign/n;
	}
	pi=pi*4;
	printf("pi=%10.8f",pi);/*在求pi的过程中，最终结果的前几位数字是正确的，
	与保留的小数位数无关，在域宽和小数位允许时，后面的几位小数还是不准确，原因是精度不够，
	若将fabs(term)范围不断缩小，得到的数据也会越来越准确。*/ 
	return 0;
	
}
