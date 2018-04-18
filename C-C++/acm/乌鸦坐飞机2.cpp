#include<stdio.h>
#include<math.h>
int num[1000000];
int main()
{
	int ans[10],count = 0;
		for(int k = 1;k <= 1000000;k++)
			{
				int i = 0,l = k;
				while(l)
				{
					ans[i] = l%10; 
					l /= 10;
					i++;
				}
				for(int j = i-1;j >= 0;j--)
				{
					if(ans[j] == 4||(ans[j] == 2&&ans[j - 1] == 3&&ans[j - 2] == 3))
					{
						count++;
						break;
					}
				}
				num[k] = k-count;
			}	
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		if(n > m)
		{
			int t = n;
			n = m;
			m = t;
		}
	printf("%d\n",num[m] - num[n-1]);
	}
	return 0;
}
