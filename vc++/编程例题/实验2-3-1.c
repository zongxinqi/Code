#include<stdio.h>
#include<string.h>
#define N 150
int compare(char longstring[],char a[N]);
int main()
{
	int i,grade;
	char longstring[]={"I will not make the same mistakes that you did,I will not let myself" 
	" cause my heart so much misery ."},a[N];
//	i=strlen(longstring);
//	printf("%d\n",i);
printf("___________________________________________________________________________________________________\n");
for(i=0;i<strlen(longstring);i++)
{ 	printf("%c",longstring[i]);
}
printf("\n___________________________________________________________________________________________________\n");
grade=compare(longstring,a);
printf("grade is %d",grade);
	return 0;
}
int compare(char longstring[],char a[N])
{
	int i,j=0;
	gets(a);/*遇到回车结束输入*/
for(i=0;i<strlen(longstring);i++)
{
	if(longstring[i]==a[i])
	j++;
}
return j;
}
