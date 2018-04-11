#include<cstdio>
#include<set>
using namespace std;
int main()
{
	int da,n;
	scanf("%d%d",&da,&n);
	for(int i = da;i < 3013;i++)
	{
		int num = i;
		set<int> s;
		for(int j = 0;j < 4;j++)
		{
			s.insert(num%10);
			num/=10;
		}
		if(s.size() == n)
		{
			printf("%d %04d",i - da,i);
			break;
		}
	}
	return 0;
}
