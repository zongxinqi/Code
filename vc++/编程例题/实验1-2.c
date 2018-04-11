#include<stdio.h>
int main()
{
int i,j,num[4][4]={5,9,10,12,4,6,7,8,11,23,20,1,3,2,40,14},sum=0;
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
printf("%3d",num[i][j]);
if(i==j)
{
	sum=sum+num[i][j];
}
}
printf("\n");
}
printf("sum=%d\n",sum);
return 0;
}

