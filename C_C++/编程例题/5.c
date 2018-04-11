#include<stdio.h>
void main()
{
    struct cmplx{
      int x;
      int y;
   }cnum[2]={1,3,2,7};
   printf("%d\n",cnum[0].y/cnum[0].x*cnum[1].x);
}
