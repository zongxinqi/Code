#include<stdio.h>
int main()
{
	float faheight,moheight,height;
	char sex,sports,diet;
	scanf("%c,%c,%c,%f,%f",&sex,&sports,&diet,&faheight,&moheight);
	if(sex=='m')
	{
	height=(faheight+moheight)*0.54;
	if(sports=='y')
	{
		height=height*1.02;
	}
	if(diet=='y')
	{
		height=height*1.02;
	}
}
	else
	{
	height=(faheight*0.923+moheight)/2;
	if(sports=='y')
	{
		height=height*1.02;
	}
	if(diet=='y')
	{
		height=height*1.02;
	}
}
	printf("height=%f\n",height);
	return 0;
}
