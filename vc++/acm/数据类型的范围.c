#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{
	printf("char:      %d\t %d\t\n",CHAR_MIN,CHAR_MAX);
	printf("short int: %d\t %d\t\n",SHRT_MIN,SHRT_MAX);
	printf("int:       %d\t %d\t\n",INT_MIN,INT_MAX);
	printf("long:      %ld\t %ld\t\n",LONG_MIN,LONG_MAX);
	printf("float: %f %f\n",FLT_MIN,FLT_MAX);
	printf("double: %lf %lf\n",DBL_MIN,DBL_MAX);
	printf("long long: %lld\t %lld\t\n",LONG_LONG_MIN,LONG_LONG_MAX);
	return 0;	
} 
