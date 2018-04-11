#include<stdio.h>
int divide(int n,int num[4]);
int paixu(int num[4]);
int main()
{
	int n,max,num[4];
	printf("please input a number:");
	scanf("%d",&n);
	divide(n,num);
    paixu(num);
max=num[0]*1000+num[1]*100+num[2]*10+num[3];
printf("%d",max);
	return 0;
}
int divide(int n,int num[4])
{
	int a,b,c,d;
	num[3]=d=n%10;
	num[2]=c=(n-d)/10%10;
	num[0]=a=n/1000;
	num[1]=b=(n-a*1000)/100;
	printf("%d %d %d %d\n",a,b,c,d);
}
int paixu(int num[4])
{
	int i,j,k,temp;
	for(i=0;i<4;i++)
    {
	k=i;
	for(j=i+1;j<4;j++)
	{
        if(num[j]>num[k])
	    k=j;
	}
	    if(k!=i)
	    {
		    temp=num[i];
		    num[i]=num[k];
		    num[k]=temp;
	    }	    
}
}
