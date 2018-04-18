#include<stdio.h>
void main()
{
  int a,b,c,d,e;
  char ch;
  printf("please enter the number:");
  a=0,b=0,c=0,d=0,e=0;
  while((ch=getchar())!='\n')
  {
    if(ch>='A'&&ch<='Z')
    a++;
    else if(ch>='a'&&ch<='z')
    b++;
    else if(ch>='0'&&ch<='9')
    c++;
    else if(ch==' ')
    d++;
    else
     e++;
  }
  printf("a=%d\nb=%d\nc=%d\nd=%d\ne=%d\n",a,b,c,d,e);
}

