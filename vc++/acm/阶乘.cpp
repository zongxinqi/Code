#include<iostream>
using namespace std;
int main()
{
	int ca,ra;
	cin>>ra>>ca;
	int a[ra][ca];
	for(int i = 0;i < ra;i++)
	{
		for(int j = 0;j < ca;j++)
	 	cin>>a[i][j]; 
	}
	int cb,rb;
	cin>>rb>>cb;
	int b[rb][cb];
	for(int i = 0;i < rb;i++)
	{
		for(int j = 0;j < cb;j++)
		cin>>b[i][j];
	}
	int ans[ra][cb];
	int i,j,sum;
	if(ca != rb)
	cout<<"Error: "<<ca<<" != "<<rb<<endl;
	else 
	{
		cout<<ra<<" "<<cb<<endl;
		for(i = 0;i < ra;i++)
		{
			for(j = 0;j < cb;j++)
			{
				sum = 0;
				for(int k = 0;k < ca;k++)
				sum += a[i][k]*b[k][j];
				ans[i][j] = sum;
			}
		}
		for(i = 0;i < ra;i++)
		{
			for(j = 0;j < cb;j++)
			{
			if(j != 0)cout<<" ";
			cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
