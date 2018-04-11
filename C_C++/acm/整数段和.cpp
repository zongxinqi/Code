#include<iostream>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int count = 0,sum = 0;
	for(int i = a;i <= b;i++)
	{
		printf("%5d",i);
		count++;
		sum += i;
		if(count % 5 == 0||i == b) printf("\n");	
	} 
	printf("Sum = %d",sum);
	return 0;
}
