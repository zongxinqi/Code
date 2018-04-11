#include<stdio.h>
int main()
{
	int a,b,c,n=0;
	for(a=0;a<=1000;a++)
	    {for(b=0;b<=200;b++)
	        {for(c=0;c<=100;c++)
	            {if(a*0.1+b*0.5+c*1==1)
	                {printf("a=%d b=%d c=%d\n",a,b,c);
	                 n++;
	                }
	            }
	        }
	    }
	printf("%d\n",n);
	return 0;
}
