#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char c[20];
	int m,n;
	cin>>n;
	char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
	int k = n;
	int count = 0;
	getchar();
	while(k--)
	{
		gets(c);
		int flag = 1;
		for(int i = 0;i < strlen(c) - 1;i++)
		{
			if(c[i] < '0'||c[i] > '9') {flag = 0;break;}
		}
		if(flag == 0)
		{
			for(int i = 0;i < strlen(c);i++)
			cout<<c[i];
			cout<<endl;
		}
		else 
		{
			m = (7*(c[0] - '0') + 9*(c[1] - '0') + 10*(c[2] - '0') + 5*(c[3] - '0') + 8*(c[4] - '0')
			+ 4*(c[5] - '0') + 2*(c[6] - '0') + (c[7] - '0') + 6*(c[8] - '0') + 3*(c[9] - '0') + 
			7*(c[10] - '0') + 9*(c[11] - '0') + 10*(c[12] - '0') + 5*(c[13] - '0') + 8*(c[14] - '0') +
			4*(c[15] - '0') + 2*(c[16] - '0')) % 11;
			if(M[m] == c[17]) 
			count++;
			else 
			{
				for(int i = 0;i < strlen(c);i++)
				cout<<c[i];
				cout<<endl;
			}
		}
	}
	if(count == n) cout<<"All passed";
	return 0;
}
