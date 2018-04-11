#include<stdio.h>
#include<math.h>
int main()
{
	int x,k,i;
	printf("please input x:");
	scanf("%d",&x);
	k=sqrt(x);
	for(i=2;i<=k;i++)
	if(x%i==0)
	break;
	if(i<=k)
	printf("%d不是素数",x);
	else printf("%d是素数",x);
	return 0;
}
