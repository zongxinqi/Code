#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
main()
{
	int r,c,i,j,k,count;
	int num[230][230],sum[230][230],max[100000];
	while(cin>>r>>c&&r&&c)
	{
		k = 1,count = 1;
		memset(sum,0,sizeof(sum));
		memset(max,0,sizeof(max));
		max[0] = 1;
		for(i = 1;i <= r;i++)
		{
			for(j = 1;j <= c;j++)
				cin>>num[i][j];
		}
		for(i = 1;i <= r;i++)
		{
			for(j = 1;j <= c;j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + num[i][j];
		}
				for(i  = 1;i <= r;i++)
			{
				for(j = 2;j <= c;j++)
				{
					if(num[i][j] == num[i][j-1]) 
					{
						count++;
						{
							if(i+count-1 <= r)
							{
								int t=sum[i+count-1][j] - sum[i-1][j] - sum[i+count-1][j-count] + sum[i-1][j-count];
								if(t==count*count||t==0)
								{	
									max[k] = count*count;
									k++;
								}
								else count = 1;
							}
						}
					}
					else count = 1;
				}
			}
			sort(max,max+k);
			cout<<max[k-1]<<endl;
	}
}
