#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i =0;i < n;i++)
	{
		int id = -1;
		int h,m;
		char c;
		int flag[1010] = {0};
		int minute[1010] = {0};
		int num = 0;
		float time = 0;
		while(id != 0)
		{
			scanf("%d %c %d:%d",&id,&c,&h,&m);
			if(id == 0) break;
			else if(c == 'S')
			{
				flag[id] = 1;
				minute[id] = h*60 + m;	
			}
			else if(c == 'E')
			{
				if(flag[id])
				{
					flag[id] = 0;
					time += h*60 + m - minute[id];
					num++;
					minute[id] = 0;	
				}	
			}	
		}
		if(num != 0) time /= num;
		printf("%d %.f\n",num,time);	
	}	
} 
