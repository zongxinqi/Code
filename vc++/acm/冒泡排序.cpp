#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int a[5] = {5,4,3,2,1};
	int i;
	for(i = 0;i < 4;i++)
	{
		for(int j = 0;j < 4 - i;j++){if(a[j] > a[j + 1]) swap(a[j],a[j + 1]);}
	}
	for(i = 0;i < 5;i++){	printf("%d",a[i]);
	}
}
