#include<stdio.h>
int main() 
{
	int m,n,i,p,q,x,c;
	printf("please input m,n:");
	scanf("%d,%d",&m,&n);
	for(i=1;i<=m;i++)
	{if(m%i==0)
	{p=n%i;
	if(p==0)
	q=i;/*循环的过程就是从1开始找公约数，满足条件后，将值赋给q，最后输出的q即为最大公约数*/
	}
	}
	for(x=m;x<=m*n;x++)
	{
	if(x%m==0)
	{
		if(x%n==0)/*最小公倍数必定大于等于其中一个数，且小于等于两个数的乘积，当x满足对m,n取余都为0时，
		即满足条件，跳出循环，输出x*/ 
		break;
	}	
	}
	printf("m,n的最大公约数=%d\n最小公倍数=%d\n",q,x);
	return 0;
}
