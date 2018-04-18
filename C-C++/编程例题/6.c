  int fun(int a[],int n)
{ int s=0,i=0;
 for(i=0;i<n;i++)s+=a[i];
 return s; } 
void main()
{ int a[10]={1,2,3,4,5};
     printf("%d", fun(&a[1],3)); }				
