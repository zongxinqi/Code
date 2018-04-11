#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct TVshow{int s,e;}show[103];
bool cmp(TVshow t1,TVshow t2)
{
	if(t1.e < t2.e)
		return true;
	else return false;
}
int main()
{
	int n,i;
	while(cin>>n,n != 0)
	{
		memset(show,0,sizeof(show));
		int count = 0;
		for(i = 0;i < n;i++)
		cin >> show[i].s >> show[i].e;
		sort(show,show+n,cmp);
		int end = show[0].e;
		count++;
		for(i = 1;i < n;i++)
		{
			if(show[i].s >= end)
			{
				end = show[i].e;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
