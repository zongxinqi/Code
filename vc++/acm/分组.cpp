#include<iostream>
#include<cstring>
using namespace std;
typedef struct student
{
	int num;
	string s;
}STU;
int main()
{
	int n;
	cin>>n;
	STU S[n];
	for(int i = 0;i < n;i++)
		cin>>S[i].num>>S[i].s;
	int i,j;
	int flag[n] = {0};
	for(i = 0;i < n/2;i++)
	{
		for(j = n-1;j >= n/2;j--)
		{
			if((S[i].num != S[j].num)&&flag[j] == 0)
			{
				flag[j] = 1;
				cout<<S[i].s<<" "<<S[j].s<<endl;
				break;
			}
		}
	}
	return 0;
} 
