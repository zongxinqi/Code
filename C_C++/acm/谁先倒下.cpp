#include<iostream>
using namespace std;
int main()
{
	int p,q;
	cin>>p>>q;
	int n;
	cin>>n;
	int coa[n][4];
	int i,j;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < 4;j++)
		cin>>coa[i][j];
	}
	int a = 0,b = 0;
	for(i = 0;i < n;i++)
	{
		if(coa[i][0] + coa[i][2] == coa[i][1]&&coa[i][0] + coa[i][2] == coa[i][3])continue;
		else
		{
			if(coa[i][0] + coa[i][2] == coa[i][1]) a++;
			else if(coa[i][0] + coa[i][2] == coa[i][3]) b++;
		}
		if(a > p) 
		{
			cout<<"A"<<endl;
			cout<<b;
			break;
		}
		if(b > q) 
		{
			cout<<"B"<<endl;
			cout<<a;
			break;
		}
	}
	return 0;
}
