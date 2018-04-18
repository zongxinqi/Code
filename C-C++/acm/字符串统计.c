//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i,n,count;
//	char x;
//	scanf("%d",&n);
//	for(i = 0;i < n;i++)
//	{
//		while(scanf("%c",&x)&&x!='\n')
//		{
//			if(x>='0'&&x<='9') count++;
//		}
//		printf("%d\n",count);
//	}
//}
#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,count,len;
	char x[1000];
	scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			count = 0;
			scanf("%s",x);
			len = strlen(x);
			while(len--)
			{
				if(x[len] >= '0'&&x[len] <= '9')
				count++;
			}
			printf("%d\n",count);
		}
}
