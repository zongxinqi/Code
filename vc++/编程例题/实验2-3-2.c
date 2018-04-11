#include<stdio.h>
int num(int a,int b,int c,int d,int j);
int main()
{
    int a,b,c,d,j=0,i=0;
    i=num(a,b,c,d,j);
	printf("总共有%d个",i);
	return 0;
}
int num(int a,int b,int c,int d,int j)

{
	int e=0;
	for(a=0;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			for(c=0;c<10;c++)
			{
				for(d=0;d<10;d++)
				{
					if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
					{
					e=a*1000+b*100+c*10+d;
					if(e%11==0&&(d*1000+c*100+b*10+a)%11==0&&e<5000)
	                {
	                printf("%d\n",e);
	                j++;	
					}
					}
					
				}
			}
		}
	}
	return j;
}
