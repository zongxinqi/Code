#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int main()
{
	char c[52];
	gets(c);
	float count = 0;
	for(int i = 0;i < strlen(c);i++)
	{
		if(c[i] == '2') count++;
	}
	float ans;
	if(c[0] == '-') 
	{
		if((c[strlen(c) - 1] - '0') % 2 == 0)
		ans = count/(strlen(c) - 1)*1.5*2*100;
		else
		ans = count/(strlen(c) - 1)*1.5*100;
	}
	else
	{
		if((c[strlen(c) - 1] - '0') % 2 == 0)
		ans = count/strlen(c)*2*100;
		else
		ans = count/strlen(c)*100;
	}
	cout<<fixed<<setprecision(2)<<ans<<"%";
	return 0;	
} 
