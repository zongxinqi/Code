#include<stdio.h>
int main()
{
	int n,i,j,l,aux[25];
	int m[60] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i++)
			scanf("%d",&aux[i]);
		for(j = 0;j < 60;j++)
		{
			if(m[j] == aux[0])
			{
				for(l = j+1;l < j+n;l++){if(m[l] != aux[l-j]) break;}
				if(l == j+n) {printf("YES\n");break;}
			}
		}
		if(j == 60) printf("NO\n");
	}
	return 0;
}
