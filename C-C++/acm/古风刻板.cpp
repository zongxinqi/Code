#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	char s[1004];
	gets(s);
	int i,len;
	len = strlen(s)/n;
	if(len*n < strlen(s)) len++;
	for(i = 0;i < n;i++)
	{
		for(int j = len-1;j >= 0;j--)
		{
			if(i + j * n >= strlen(s))
			cout<<" ";
			else 
			cout<<s[i + j*n];
		}
		cout<<endl;	
	} 
	return 0;
}
