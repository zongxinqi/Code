#include<stdio.h>
#include<string.h>
int main()
{
	int n1,n2,n3,n4;
	int str;
	char pas[55];
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		getchar();
		while(m--)
		{
			n1 = n2 = n3 = n4 = 0;
			gets(pas);
			str = strlen(pas);
			for(int i = 0;i < str;i++)
			{
				if(pas[i] >= 'A'&&pas[i] <= 'Z') n1 = 1;
				else if(pas[i] >= 'a'&&pas[i] <= 'z') n2 = 1;
				else if(pas[i] >= '0'&&pas[i] <= '9') n3 = 1;
				else n4 = 1;
			}
			if(str>=8&&str<=16&&(n1+n2+n3+n4)>=3) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
