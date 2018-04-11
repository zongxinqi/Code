#include<stdio.h>
int compare(int *a,int n);
int main()
{
	int i,j,k=0,n,num[30],p[60],q[60],*a=p,*b=q;
	printf("please input the number of the array:"); scanf("%d",&n);
	for(i=0;i<n;i++) 
	{
		scanf("%d",&num[i]);
	    *(a+i)=num[i];
	}
	compare(a,n);
	
	
	//将数组进行删除操作 
	for(i=0;i<n-1;i++){
	    if(*(a+i)<*(a+i+1))
	    {
		*(b+k)=*(a+i);
	    k++;
		}
	}
	if(p[n-1]!=p[n-2])
	q[k]=p[n-1];
//	for(i=0;i<=k;i++)
//	printf("%d",q[i]);


//与删除后的数组相比较,得出对应的序号 
	for(i=0;i<n;i++)
	{
	   for(j=0;j<k;j++)
	   {
	   	if(num[i]==*(b+j))
		   break; 
	   }
	   *(a+i+30)=j+1;
	}
	for(i=30;i<n+30;i++)
	{
		printf("%d ",*(a+i));
	}
}
//将输入的数组进行排序 
int compare(int *a,int n)
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(a+i)-*(a+j)>=0)
			{
				k=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=k;
			}
		}
	}
}
