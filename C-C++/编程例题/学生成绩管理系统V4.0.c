#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 5                                                                /*�ַ�������󳤶�*/
#define N 30                                                                     /*ͳ��ѧ�����������*/
#define course_N 6                                                               /*���Կ�Ŀ��*/
int menu(void);                                                                  /*�˵�����*/ 
void readscore(float score[][course_N],long num[],char name[][max_len],int n);                   /*����ɼ���ѧ�ź�����*/ 
float averagestu(float score[][course_N],float sumstu[N],float averstu[N],int n);                                              /*��ɼ���ƽ��ֵ*/
float sumscorestu(float score[][course_N],float sumstu[N],int n);
float sumscorecou(float score[][course_N],float sumcou [N],int n);
float averagecou(float score[][course_N],float sumcou[course_N],float avercou[course_N],int n);
void scoresort(float score[][course_N],float sumstu[N],float averstu[N],long num[],char name[][max_len],int n);             /*���ɼ���������*/
void selectionsort(float score[][course_N],float sumstu[N],float averstu[N],int n,long num[],char name [][max_len],float (*compare)(float a,float b));
float ascending(float a,float b);
void swap(float*x,float*y);
void longswap(long *x,long *y);
void charswap(char x[],char y[]);                                                      /*���ɼ���������*/ 
void sortstring(float score[][course_N],long num[],char name[][max_len],int n);                                     /*���������ֵ�˳�����*/
void numsort(float score[][course_N],long num[],char name[N][max_len],int n);              /*��ѧ����������*/ 
int search(float score[][course_N],long num[],char name[][max_len],int n,long x1);         /*ͨ��ѧ�Ž��в���*/
int namesearch(float score[][course_N],long num[],char name[][max_len],int n,char x[max_len]);     /*���������в���*/
void analysis(float score[][course_N],int n);                                              /*�ɼ�����*/ 
void print(float score[][course_N],float sumstu[N],float averstu[N],float sumcou[course_N],float avercou[course_N],long num[],char name[][max_len],int n);                 /*���ѧ���ĳɼ���ѧ��*/ 
int main()
{
	int cho,n,flag1,flag2,i,j;                                                              /*�������α�������ѡ���ѧ�������Ͳ��Һ�ķ���ֵ*/
	float sumstu[N],averstu[N],sumcou[course_N],avercou[course_N],score[N][course_N];                                                     /*����ʵ�͵��ܺͣ�ƽ��ֵ��ѧ���ɼ�*/
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
		           for(i=0;i<n;i++)
				   {
				   	for(j=0;j<course_N;j++)
				   	   {
				   		printf("%.2f ",score[i][j]);
					   }
					   printf("%ld %s\n",num[i],name[i]);
				    }          
		           break;
		    case 2:sumscorecou(score,sumcou,n);
		           averagecou(score,sumcou,avercou,n);
		           printf("the sum and average of every course:\n");
		           for(j=0;j<course_N;j++)
		           {
		           	printf("%.2f,%.2f\n",sumcou[j],avercou[j]);
				   }
				   break;
		    case 3:sumscorestu(score,sumstu,n);
		           averagestu(score,sumstu,averstu,n);
			       printf("the sum and average of every student:\n");
		           for(i=0;i<n;i++)
		           {
		           	printf("%.2f,%.2f\n",sumstu[i],averstu[i]);
				   }
		           break;
		    case 4:scoresort(score,sumstu,averstu,num,name,n);
		           print(score,sumstu,averstu,sumcou,avercou,num,name,n);
		           break;
		    case 5:selectionsort(score,sumstu,averstu,n,num,name,ascending);
		           printf("data items in ascending order\n");
		    case 6:numsort(score,num,name,n);
		           print(score,sumstu,averstu,sumcou,avercou,num,name,n);
		           break;
			case 7:sortstring(score,num,name,n);
		           printf("sorted results :\n");
				   print(score,sumstu,averstu,sumcou,avercou,num,name,n);
				   break;		        
		    case 8:printf("please input the number to search:\n");
		           scanf("%ld",&x1);
			       flag1=search(score,num,name,n,x1);
		           if(flag1==-1)
				   printf("not found!\n");
				   else 
				   for(i=0;i<course_N;i++)
				   {
				   	printf("%.2f ",score[flag1][i]);
				   }
				   printf("%ld,%s,No.%d\n",x1,name[flag1],flag1+1);
				   break;
		    case 9:printf("please input the name to search:\n");
			       scanf("%s",x);
				   flag2=namesearch(score,num,name,n,x);
				   if(flag2==-1)
				   printf("not found!\n");
				   else 
				   for(i=0;i<course_N;i++)
				   {
				   	printf("%.2f ",score[flag2][i]);
				   }
				   printf("%ld,%s\n",num[flag2],x);
				   break;                                        
		    case 10:analysis(score,n);
		           break;
		    case 11:numsort(score,num,name,n);
		           print(score,sumstu,averstu,sumcou,avercou,num,name,n);
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
        printf("2. Caculate total and average score of every course \n");
        printf("3. Caculate total and everage score of every student \n");
	    printf("4. Sort in descending order by total score of every student \n");
        printf("5. Sort in ascending order by total score of every student \n");
        printf("6. Sort in ascending order by number \n");
        printf("7. Sort in dictionary order by name \n");
	    printf("8. Search by number \n");
	    printf("9. Search by name \n");
        printf("10. Statistic analysis \n");
	    printf("11. List record \n");
        printf("0. Exit \n");
        printf("please enter your choice:\n");
        scanf("%d",&cho);
        return(cho);
}
/*����ѧ����ѧ�źͳɼ���������ѧ��������*/
void readscore(float score[][course_N],long num[],char name[][max_len],int n) 
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<course_N;j++)
		{
			scanf("%f",&score[i][j]);                            /*����ÿ��ѧ���ĸ��ſγɼ�*/
		}
		scanf("%ld,%s",&num[i],&name[i]);
	}
}
float sumscorecou(float score[][course_N],float sumcou[course_N],int n)
{
	int i,j;
	for(j=0;j<course_N;j++)
	{
		sumcou[j]=0;
		
		for(i=0;i<n;i++)
		{
			sumcou[j]=sumcou[j]+score[i][j];
		}
	}
}
float averagecou(float score[][course_N],float sumcou[course_N],float avercou[course_N],int n)
{
    int i,j;
	for(j=0;j<course_N;j++)
	{
		sumcou[j]=0;
		for(i=0;i<n;i++)
		{
			sumcou[j]=sumcou[j]+score[i][j];
		}
		avercou[j]=sumcou[j]/n;
	}
	
}
/*ѧ���ɼ��ļӺ�*/
float sumscorestu(float score[][course_N],float sumstu[N],int n)
{
 int i,j;
  for(i=0;i<n;i++)	
  {
  	sumstu[i]=0;
  	for(j=0;j<course_N;j++)
  	{
  	sumstu[i]=sumstu[i]+score[i][j];
    }
  }
}
/*��ѧ���ɼ���ƽ��ֵ*/
float averagestu(float score[][course_N],float sumstu[N],float averstu[N],int n)
{
  int i,j;
  for(i=0;i<n;i++)	
  {
  	sumstu[i]=0;
  	for(j=0;j<course_N;j++)
  	{
  	sumstu[i]=sumstu[i]+score[i][j];
    }
    averstu[i]=sumstu[i]/course_N;
  }
}
/*���ɼ�����������*/ 
void selectionsort(float score[][course_N],float sumstu[],float averstu[],int n,long num[],char name[][max_len],float (*compare)(float a,float b))
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if((*compare)(sumstu[j],sumstu[k]))
			k=j;
		}
    
		if(k!=i) 
		{
		 for(t=0;t<course_N;t++)
		 {
		 	swap(&score[k][t],&score[i][t]);
		 }
		 swap(&sumstu[k],&sumstu[i]);
		 swap(&averstu[k],&averstu[i]);
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
void scoresort(float score[][course_N],float sumstu[],float averstu[],long num[],char name[][max_len],int n)
{
	int i, j, k,t;
    for (i=0; i<n-1; i++)
    {
        k = i;
        for (j=i+1; j<n; j++)      
        {
            if (sumstu[j] > sumstu[k])
            {
                k = j;    
            }
        }
   	
        if (k != i)     
        {
        	for(t=0;t<course_N;t++)
        	{
        		swap(&score[k][t],&score[i][t]);
			}
			swap(&sumstu[k],&sumstu[i]);
			swap(&averstu[k],&averstu[i]);
            longswap(&num[k],&num[i]);
            charswap(name[k],name[i]);
        } 
    }
}
/*��ѧ����������*/
void numsort(float score[][course_N],long num[],char name[][max_len],int n)
{
  int i, j, k, t;
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
        	for(t=0;t<course_N;t++)
        	{
        		swap(&score[k][t],&score[i][t]);
			}
            temp2 = num[k]; 
            num[k] = num[i]; 
            num[i] = temp2;
            strcpy(temp3,name[k]);
			strcpy(name[k],name[i]);
			strcpy(name[i],temp3);
        }  
    }
}
/*���������ֵ�˳������*/
void sortstring(float score[][course_N],long num[],char name[][max_len],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(name[j],name[i])<0)
			{
				for(t=0;t<course_N;t++)
				{ 
			  swap(&score[j][t],&score[i][t]);
	            }     		  
			  longswap(&num[j],&num[i]);
			  charswap(name[j],name[i]);
			}
		}
	}
}
/*��ѧ�Ų���*/
int search(float score[][course_N],long num[],char name[][max_len],int n,long x1)
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
int namesearch(float score[][course_N],long num[],char name[][max_len],int n,char x[max_len])
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
void analysis(float score[][course_N], int n)
{
	int  i, j,t,stu[N][6];     /* stu[]-���鳤��Ϊ6,�������6���ɼ����ε����� */ 
	for(t=0;t<course_N;t++)
	{
			memset(stu,0,sizeof(stu));
	for (i=0; i<n; i++)
	{
		if (score[i][t] < 60)    
			j = 0;          /* stu[]�����±�Ϊ0ʱ, �ǲ�������� */ 
		else
			j = ((int)score[i][t] - 50) / 10;    /* ���ݾ���ɼ�����,ȷ�������ĸ��ɼ����� */ 
		stu[t][j]++;         
	} 
	for (j=0; j<6; j++)     /* ��������ε�������������� */  
	{
		if (j == 0)
			printf("< 60    %d  %.2f%%  ", stu[t][j], (float)stu[t][j]/(float)n*100);
		else if (j == 5)
				printf("   %d  %d  %.2f%%\n", (j+5)*10, stu[t][j],	(float)stu[t][j]/(float)n*100);
			else
		       	printf("%d--%d  %d  %.2f%%  ", (j+5)*10,(j+5)*10+9,	stu[t][j],(float)stu[t][j]/(float)n*100);
    }
	}
}
 /*���ѧ�ż��ɼ�*/
 void print(float score[][course_N],float sumstu[N],float averstu[N],float sumcou[course_N],float avercou[course_N],long num[],char name[][max_len],int n)
 {  
    int i,j;
 	for(i=0;i<n;i++)
 	{
	printf("%ld\t%s       ",num[i],name[i]);
 	for(j=0;j<course_N;j++)
 	{
 	printf("%.2f\t",score[i][j]);	
	}
	printf("%.2f\t%.2f\n",sumstu[i],averstu[i]);
    }
	printf("sumofcourse\t");
	for(j=0;j<course_N;j++)
	{
		printf("%.2f\t",sumcou[j]);
    }
    printf("\naverofcourse\t");
    for(j=0;j<course_N;j++)
    {
    	printf("%.2f\t",avercou[j]);
	}
	printf("\n");
}

 
