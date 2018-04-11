#include<stdio.h>
int main()
{
	int n,flag,count,beg[100],end[100],i,j;
	while(~scanf("%d",&n)&&n)
	{
		for(i = 0;i < n;i++)
		scanf("%d%d",beg+i,end+i);
		count = 0;
		for(i = 0;i < n;i++)
		{
			flag = 0;
			for(j = 0;j < n;j++)
			{
				if((beg[i] >= beg[j]&&end[i] <= end[j])||(beg[i] >= end[j])||(end[i] <= beg[j]))
				flag++;
			}
			if(flag == n) count++;
		}
		printf("%d\n",count);
	} 
}
