#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int i,y,m,d,sum;
	int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d/%d/%d",&y,&m,&d) != EOF)
	{
		sum = 0;
		for(i = 0;i < m-1;i++)
		sum+=mon[i];
		sum+=d;
  		if(((y % 4==0 && y % 100 != 0) || (y % 400 == 0)) && m > 2)
  		sum++;
  		cout<<sum<<endl;
	}
	return 0;
}
