#include<stdio.h>
int main ()
{
	printf ("data type       number of bytes\n");
	printf ("------------    --------------------\n");
	printf ("char            %d\n",sizeof(char)) ;
	printf ("int             %d\n",sizeof(int));
	printf ("short int       %d\n",sizeof(short));
	printf ("long int        %d\n",sizeof (long));
	printf ("float           %d\n",sizeof (float));
	printf ("double          %d\n",sizeof (double));
}
