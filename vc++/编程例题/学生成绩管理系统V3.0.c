#include <stdio.h>
#include <string.h>
#define max_len 5                                                                /*�ַ�������󳤶�*/
#define N 30                                                                     /*ͳ��ѧ�����������*/
int menu(void);                                                                  /*�˵�����*/ 
void readscore(float score[],long num[],char name[][max_len],int n);                   /*����ɼ���ѧ�ź�����*/ 
float average(float score[],int n);                                              /*��ɼ���ƽ��ֵ*/
float sumscore(float score[],int n);                                             /*�Գɼ����*/ 
void scoresort(float score[],long num[],char name[][max_len],int n);             /*���ɼ���������*/
void selectionsort(float a[],int n,long num[],char name [][max_len],float (*compare)(float a,float b));
float ascending(float a,float b);
void swap(float*x,float*y);
void longswap(long *x,long *y);
void charswap(char x[],char y[]);                                                      /*���ɼ���������*/ 
void sortstring(float score[],long num[],char name[][max_len],int n);                                     /*���������ֵ�˳�����*/
void numsort(float score[],long num[],char name[N][max_len],int n);              /*��ѧ����������*/ 
int search(float score[],long num[],char name[][max_len],int n,long x1);         /*ͨ��ѧ�Ž��в���*/
int namesearch(float score[],long num[],char name[][max_len],int n,char x[max_len]);     /*���������в���*/
void analysis(float score[],int n);                                              /*�ɼ�����*/ 
void print(float score[],long num[],char name[][max_len],int n);                 /*���ѧ���ĳɼ���ѧ��*/ 
int main()
{
	int cho,n,flag1,flag2;                                                              /*�������α�������ѡ���ѧ�������Ͳ��Һ�ķ���ֵ*/
	float sum,aver,score[N];                                                     /*����ʵ�͵��ܺͣ�ƽ��ֵ��ѧ���ɼ�*/
	long num[N],x1;                                                              /*���峤���͵�ѧ�ź�Ҫ���ҵĺ���*/ 
	char name[N][max_len],x[max_len];                                                       /*���������Ķ�ά����*/
	printf("please input the number of students:");
	scanf("%d",&n);
	while(1)
	{
		cho=menu();
		switch(cho)
		{
			case 0:printf("End of program! \n");
			       exit(0);            
		    case 1:printf("please input score,number and name:\n");
				   readscore(score,num,name,n);
		           printf("total students are %d\n",n);
		           print(score,num,name,n);
		           break;
		    case 2:sum=sumscore(score,n);
		           printf("sum=%f\n",sum);
		           aver=average(score,n);
		           printf("average=%f\n",aver);
		           break;
		    case 3:scoresort(score,num,name,n);
		           print(score,num,name,n);
		           break;
		    case 4:selectionsort(score,n,num,name,ascending);
		           printf("data items in ascending order\n");
		    case 5:numsort(score,num,name,n);
		           print(score,num,name,n);
		           break;
			case 6:sortstring(score,num,name,n);
		           printf("sorted results :\n");
				   print(score,num,name,n);
				   break;		        
		    case 7:printf("please input the number to search:\n");
		           scanf("%ld",&x1);
			       flag1=search(score,num,name,n,x1);
		           if(flag1==-1)
				   printf("not found!\n");
				   else printf("%.2f,%ld,%s,No.%d\n",score[flag1],x1,name[flag1],flag1+1);
				   break;
		    case 8:printf("please input the name to search:\n");
			       scanf("%s",x);
				   flag2=namesearch(score,num,name,n,x);
				   if(flag2==-1)
				   printf("not found!\n");
				   else printf("%.2f,%ld,%s\n",score[flag2],num[flag2],x);
				   break;                                        
		    case 9:analysis(score,n);
		           break;
		    case 10:numsort(score,num,name,n);
		           print(score,num,name,n);
		           break;
		    
		    default:printf("data error!\n");
		}
		
	}
	return 0;
}
/*����˵�����������ѡ��ֵ���޲��� */
int menu(void)
{
	int cho;
	    printf("1. Input record \n");
        printf("2. Caculate total and average of course \n");
	    printf("3. Sort in descending order by score \n");
        printf("4. Sort in ascending order by score \n");
        printf("5. Sort in ascending order by number \n");
        printf("6. Sort in dictionary order by name \n");
	    printf("7. Search by number \n");
	    printf("8. Search by name \n");
        printf("9. Statistic analysis \n");
	    printf("10. List record \n");
        printf("0. Exit \n");
        printf("please enter your choice:\n");
        scanf("%d",&cho);
        return(cho);
}
/*����ѧ����ѧ�źͳɼ���������ѧ��������*/
void readscore(float score[],long num[],char name[][max_len],int n) 
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%f,%ld,%s", &score[i], &num[i],name[i]);
	}
}
/*ѧ���ɼ��ļӺ�*/
float sumscore(float score[],int n)
{
 int i,sum=0;
  for(i=0;i<n;i++)	
  {
  	sum=sum+score[i];
  }
  return sum;
}
/*��ѧ���ɼ���ƽ��ֵ*/
float average(float score[],int n)
{
  int i,sum=0;
  for(i=0;i<n;i++)	
  {
  	sum=sum+score[i];
  }	
  return sum/n;
}
/*���ɼ�����������*/ 
void selectionsort(float a[],int n,long num[],char name[][max_len],float (*compare)(float a,float b))
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if((*compare)(a[j],a[k]))
			k=j;
		}
		if(k!=i) 
		{
         swap(&a[k],&a[i]);
         longswap(&num[k],&num[i]);
         charswap(name[k],name[i]);
        }
	}
}
float ascending(float a,float b)
{
	return a<b;
}
void swap(float*x,float*y)
{
	float temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void longswap(long*x,long*y)
{
    long temp1;
	temp1=*x;
	*x=*y;
	*y=temp1;
}
void charswap(char x[],char y[])
{
	char temp2[max_len];
	strcpy(temp2,x);
	strcpy(x,y);
	strcpy(y,temp2);
}
/*���ɼ���������*/ 
void scoresort(float score[],long num[],char name[][max_len],int n)
{
	int i, j, k;
    for (i=0; i<n-1; i++)
    {
        k = i;
        for (j=i+1; j<n; j++)      
        {
            if (score[j] > score[k])
            {
                k = j;    
            }
        }
        if (k != i)     
        {
            swap(&score[k],&score[i]);
            longswap(&num[k],&num[i]);
            charswap(name[k],name[i]);
        }  
    }
}
/*��ѧ����������*/
void numsort(float score[],long num[],char name[][max_len],int n)
{
  int i, j, k, temp1;
    long temp2;
	char temp3[max_len];	
     for (i=0; i<n-1; i++)
    {
        k = i;
        for (j=i+1; j<n; j++)      
        {
            if (num[j] <num[k])
            {
                k = j;    /*��¼��Сѧ�ŵ��±�λ��*/
            }
        }
        if (k != i)       /*����Сѧ�Ų����±�λ��i*/
        {
            temp1 = score[k];
            score[k] = score[i];
            score[i] = temp1; 
            temp2 = num[k]; 
            num[k] = num[i]; 
            num[i] = temp2;
            strcpy(temp3,name[k]);
			strcpy(name[k],name[i]);
			strcpy(name[i],temp3);
        }  
    }
}
/*������������ĸ����*/
void sortstring(float score[],long num[],char name[][max_len],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(name[j],name[i])<0)
			{
			  swap(&score[j],&score[i]);
			  longswap(&num[j],&num[i]);
			  charswap(name[j],name[i]);
			}
		}
	}
}
/*��ѧ�Ų���*/
int search(float score[],long num[],char name[][max_len],int n,long x1)
{   
    numsort(score,num,name,n);
    int  low, high, mid;
	low = 0;  
	high = n - 1;        
	while (low <= high)
	{
   	mid = (high + low) / 2; 
		if (x1 > num[mid])   
   	{
			low = mid + 1; 
   	}
		else  if (x1 < num[mid])  
		{
			high = mid - 1; 
   	}
		else  
		{
			return mid; 
   	}
   	
	}
	return -1; 
}
/*ͨ���������в���*/
int namesearch(float score[],long num[],char name[][max_len],int n,char x[max_len])
{
	sortstring(score,num,name,n);
	int low=0,mid,high=n-1;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(strcmp(x,name[mid])>0)
		{
			low=mid+1;
		}
		else if(strcmp(x,name[mid])<0)
	{
		high=mid-1;
	}
	    else 
	    return mid;
	}
	return -1;
	/*int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(name[i],x)==0)
		return i;
	}
	return -1;*/
}
/*�������������ռ����*/
void analysis(float score[], int n)
{
	int  i, j, stu[6];     /* stu[]-���鳤��Ϊ6,�������6���ɼ����ε����� */ 
	for (i=0; i<6; i++)
		stu[i]=0;
	for (i=0; i<n; i++)
	{
		if (score[i] < 60)    
			j = 0;          /* stu[]�����±�Ϊ0ʱ, �ǲ�������� */ 
		else
			j = ((int)score[i] - 50) / 10;    /* ���ݾ���ɼ�����,ȷ�������ĸ��ɼ����� */ 
		stu[j]++;          /* ����Ӧ�ĳɼ������Ͻ�������1 */  
	}
	for (i=0; i<6; i++)     /* ��������ε�������������� */  
	{
		if (i == 0)
			printf("< 60    %d  %.2f%%\n", stu[i], (float)stu[i]/(float)n*100);
		else if (i == 5)
				printf("   %d  %d  %.2f%%\n", (i+5)*10, stu[i],	(float)stu[i]/(float)n*100);
			else
		       	printf("%d--%d  %d  %.2f%%\n", (i+5)*10,(i+5)*10+9,	stu[i],(float)stu[i]/(float)n*100);
	}
}
 /*���ѧ�ż��ɼ�*/
 void print(float score[],long num[],char name[][max_len],int n)
 {  
    int i;
 	for(i=0;i<n;i++)
 	printf("%.2f,%ld,%s\n",score[i],num[i],name[i]);
 }

 
