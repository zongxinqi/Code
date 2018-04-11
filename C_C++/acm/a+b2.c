#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,lena,lenb,max,x,y,c[100] = {0},sum[100] = {0};
	char a[100],b[100];
	while(~scanf("%d",&n)&&n)
	{
			getchar();
			while(n--)
		{
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			scanf("%s%s",&a,&b); 
			lena = strlen(a);
			lenb = strlen(b);
			max = lena>=lenb?lena:lenb;
			for(i = 0;i < lena/2;i++)
			{
				a[i]+=a[lena-1-i];
				a[lena-1-i]=a[i]-a[lena-1-i];
				a[i]-=a[lena-1-i];
			}
			for(i = 0;i < lenb/2;i++)
			{
				b[i]+=b[lenb-1-i];
				b[lenb-1-i]=b[i]-b[lenb-1-i];
				b[i]-=b[lenb-1-i];
			}
			for(i = 0;i <= max;i++)
			{
				if(i < lena) x = a[i] - '0';else x = 0;
				if(i < lenb) y = b[i] - '0';else y = 0;
				if(i == 0) c[i] = x+y;
				else c[i] = x + y + c[i-1]/10; 
				sum[i] = c[i]%10;
			}
			if(sum[max] > 0) printf("%d",sum[max]);
			for(i = max-1;i >= 0;i--)
				printf("%d",sum[i]);
			printf("\n");
		}
	}
	return 0;
}
