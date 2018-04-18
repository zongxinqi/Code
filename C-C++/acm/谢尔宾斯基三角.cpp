#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	int n,i,j = 1,k,l;
	string a = " -- ";
	string b = "\\  /";
	string c = " \\/ ";
	string d,e,f,h;
	string g = "  ";
	while(cin >> n)
	{
		j = pow(2,n-1);
	while(j > 0)
	{
		e = d = f = ""; 
			for(i = 1;i <= j;i++)
			{
				if(j == n&&(i == 2||i == 3))
				{
					d += g;
					e += g;
					f += g;
				}
				else
				{
					d += a;
					e += b;
					f += c;
				}
					h = "";
					for(k = pow(2,n-1);k > j;k--)
					{
						h+=g;
					}
			}
		cout << h << d << endl << h << e << endl << h << f << endl;
		j--;
	}
	}
	return 0;
}
