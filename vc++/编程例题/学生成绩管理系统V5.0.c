#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 5                                                                /*�ַ�������󳤶�*/
#define N 30                                                                     /*ͳ��ѧ�����������*/
#define course_N  6                                                              /*���Կ�Ŀ��*/
typedef struct student 
{
	float score[course_N];
	long num;
	char name[max_len];
}STUDENT;
int menu(void);                                                                  /*�˵�����*/ 
void readscore(STUDENT stu[],int n,int coursen);                   /*����ɼ���ѧ�ź�����*/ 
float averagestu(STUDENT stu[],float sumstu[N],float averstu[N],int n,int coursen);                                              /*��ɼ���ƽ��ֵ*/
float sumscorestu(STUDENT stu[],float sumstu[N],int n,int coursen);
float sumscorecou(STUDENT stu[],float sumcou [N],int n,int coursen);
float averagecou(STUDENT stu[],float sumcou[course_N],float avercou[course_N],int n,int coursen);
void scoresort(STUDENT stu[],float sumstu[N],float averstu[N],int n,int coursen);             /*���ɼ���������*/
void selectionsort(STUDENT stu[],float sumstu[N],float averstu[N],int n,int coursen,float (*compare)(float a,float b));
float ascending(float a,float b);
void swap(float*x,float*y);
void longswap(long *x,long *y);
void charswap(char x[],char y[]);                                                      /*���ɼ���������*/ 
void sortstring(STUDENT stu[],int n,int coursen);                                     /*���������ֵ�˳�����*/
void numsort(STUDENT stu[],int n,int coursen);              /*��ѧ����������*/ 
int search(STUDENT stu[],int n,int coursen,long x1);         /*ͨ��ѧ�Ž��в���*/
int namesearch(STUDENT stu[],int n,int coursen,char x[max_len]);     /*���������в���*/
void analysis(STUDENT stu[],int n,int coursen);                                              /*�ɼ�����*/ 
void print(STUDENT stu[],float sumstu[N],float averstu[N],float sumcou[course_N],float avercou[course_N],int n,int coursen);                 /*���ѧ���ĳɼ���ѧ��*/ 
int main()
{
	int cho,n,coursen,flag1,flag2,i,j;                                                              /*�������α�������ѡ���ѧ�������Ͳ��Һ�ķ���ֵ*/
	float sumstu[N],averstu[N],sumcou[course_N],avercou[course_N],score[N][course_N];                                                     /*����ʵ�͵��ܺͣ�ƽ��ֵ��ѧ���ɼ�*/
	long num[N],x1;                                                              /*���峤���͵�ѧ�ź�Ҫ���ҵĺ���*/ 
	char name[N][max_len],x[max_len];                                                       /*���������Ķ�ά����*/
	STUDENT stu[N];
	printf("please input the number of students:");
	scanf("%d",&n);
	printf("please input the number of courses:");
	scanf("%d",&coursen);
	while(1)
	{
		cho=menu();
		switch(cho)
		{
			case 0:printf("End of program! \n");
			       exit(0);            
		    case 1:printf("please input score,number and name:\n");
				   readscore(stu,n,coursen);
		           printf("total students are %d\n",n);
		           for(i=0;i<n;i++)
				   {
				   	for(j=0;j<coursen;j++)
				   	{
					 printf("%.2f ",stu[i].score[j]);
				    }
				    printf("%ld ",stu[i].num);
				    printf("%s\n",stu[i].name);
				    }
		           break;
		    case 2:sumscorecou(stu,sumcou,n,coursen);
		           averagecou(stu,sumcou,avercou,n,coursen);
		           printf("the sum and average of every course:\n");
		           for(j=0;j<coursen;j++)
		           {
		           	printf("%.2f %.2f\n",sumcou[j],avercou[j]);
				   }
				   break;
		    case 3:sumscorestu(stu,sumstu,n,coursen);
		           averagestu(stu,sumstu,averstu,n,coursen);
			       printf("the sum and average of every student:\n");
		           for(i=0;i<n;i++)
		           {
		           	printf("%.2f %.2f\n",sumstu[i],averstu[i]);
				   }
		           break;
		    case 4:scoresort(stu,sumstu,averstu,n,coursen);
		           print(stu,sumstu,averstu,sumcou,avercou,n,coursen);
		           break;
		    case 5:selectionsort(stu,sumstu,averstu,n,coursen,ascending);
		           printf("data items in ascending order\n");
		    case 6:numsort(stu,n,coursen);
		           print(stu,sumstu,averstu,sumcou,avercou,n,coursen);
		           break;
			case 7:sortstring(stu,n,coursen);
		           printf("sorted results :\n");
				   print(stu,sumstu,averstu,sumcou,avercou,n,coursen);
				   break;		        
		    case 8:printf("please input the number to search:\n");
		           scanf("%ld",&x1);
			       flag1=search(stu,n,coursen,x1);
		           if(flag1==-1)
				   printf("not found!\n");
				   else 
				   for(i=0;i<coursen;i++)
				   {
				   	printf("%.2f ",stu[flag1].score[i]);
				   }
				   printf("%ld %s No.%d\n",x1,stu[flag1].name,flag1+1);
				   break;
		    case 9:printf("please input the name to search:\n");
			       scanf("%s",x);
				   flag2=namesearch(stu,n,coursen,x);
				   if(flag2==-1)
				   printf("not found!\n");
				   else 
				   for(i=0;i<coursen;i++)
				   {
				   	printf("%.2f ",stu[flag2].score[i]);
				   }
				   printf("%ld %s\n",stu[flag2].num,x);
				   break;                                        
		    case 10:analysis(stu,n,coursen);
		           break;
		    case 11:numsort(stu,n,coursen);
		           print(stu,sumstu,averstu,sumcou,avercou,n,coursen);
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
void readscore(STUDENT stu[N],int n,int coursen) 
{
	int i,j;
	for(i=0;i<n;i++)
	{   
	for(j=0;j<coursen;j++)
	{
		scanf("%f",&stu[i].score[j]);
	 }                 
		scanf("%ld",&stu[i].num);
		scanf(" %s",stu[i].name);
		
	}
}
float sumscorecou(STUDENT stu[],float sumcou[course_N],int n,int coursen)
{
	int i,j;
	for(j=0;j<coursen;j++)
	{
		sumcou[j]=0;
		
		for(i=0;i<n;i++)
		{
			sumcou[j]=sumcou[j]+stu[i].score[j];
		}
	}
}
float averagecou(STUDENT stu[],float sumcou[course_N],float avercou[course_N],int n,int coursen)
{
    int i,j;
	for(j=0;j<coursen;j++)
	{
		sumcou[j]=0;
		for(i=0;i<n;i++)
		{
			sumcou[j]=sumcou[j]+stu[i].score[j];
		}
		avercou[j]=sumcou[j]/n;
	}
	
}
/*ѧ���ɼ��ļӺ�*/
float sumscorestu(STUDENT stu[],float sumstu[N],int n,int coursen)
{
 int i,j;
  for(i=0;i<n;i++)	
  {
  	sumstu[i]=0;
  	for(j=0;j<coursen;j++)
  	{
  	sumstu[i]=sumstu[i]+stu[i].score[j];
    }
  }
}
/*��ѧ���ɼ���ƽ��ֵ*/
float averagestu(STUDENT stu[],float sumstu[N],float averstu[N],int n,int coursen)
{
  int i,j;
  for(i=0;i<n;i++)	
  {
  	sumstu[i]=0;
  	for(j=0;j<coursen;j++)
  	{
  	sumstu[i]=sumstu[i]+stu[i].score[j];
    }
    averstu[i]=sumstu[i]/coursen;
  }
}
/*���ɼ�����������*/ 
void selectionsort(STUDENT stu[],float sumstu[],float averstu[],int n,int coursen,float (*compare)(float a,float b))
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
		 for(t=0;t<coursen;t++)
		 {
		 	swap(&stu[k].score[t],&stu[i].score[t]);
		 }
		 swap(&sumstu[k],&sumstu[i]);
		 swap(&averstu[k],&averstu[i]);
         longswap(&stu[k].num,&stu[i].num);
         charswap(stu[k].name,stu[i].name);
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
void scoresort(STUDENT stu[],float sumstu[N],float averstu[N],int n,int coursen)
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
        	for(t=0;t<coursen;t++)
        	{
        		swap(&stu[k].score[t],&stu[i].score[t]);
			}
			swap(&sumstu[k],&sumstu[i]);
			swap(&averstu[k],&averstu[i]);
            longswap(&stu[k].num,&stu[i].num);
            charswap(stu[k].name,stu[i].name);
        } 
    }
}
/*��ѧ����������*/
void numsort(STUDENT stu[],int n,int coursen)
{
  int i, j, k, t;
    long temp2;
	char temp3[max_len];	
     for (i=0; i<n-1; i++)
    {
        k = i;
        for (j=i+1; j<n; j++)      
        {
            if (stu[j].num <stu[k].num)
            {
                k = j;    /*��¼��Сѧ�ŵ��±�λ��*/
            }
        }
        if (k != i)       /*����Сѧ�Ų����±�λ��i*/
        {
        	for(t=0;t<coursen;t++)
        	{
        		swap(&stu[k].score[t],&stu[i].score[t]);
			}
            temp2 = stu[k].num; 
            stu[k].num = stu[i].num; 
            stu[i].num = temp2;
            strcpy(temp3,stu[k].name);
			strcpy(stu[k].name,stu[i].name);
			strcpy(stu[i].name,temp3);
        }  
    }
}
/*���������ֵ�˳������*/
void sortstring(STUDENT stu[],int n,int coursen)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(stu[j].name,stu[i].name)<0)
			{
				for(t=0;t<coursen;t++)
				{ 
			  swap(&stu[j].score[t],&stu[i].score[t]);
	            }     		  
			  longswap(&stu[j].num,&stu[i].num);
			  charswap(stu[j].name,stu[i].name);
			}
		}
	}
}
/*��ѧ�Ų���*/
int search(STUDENT stu[],int n,int coursen,long x1)
{   
    numsort(stu,n,coursen);
    int  low, high, mid;
	low = 0;  
	high = n - 1;        
	while (low <= high)
	{
   	mid = (high + low) / 2; 
		if (x1 > stu[mid].num)   
   	{
			low = mid + 1; 
   	}
		else  if (x1 < stu[mid].num)  
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
int namesearch(STUDENT stu[],int n,int coursen,char x[max_len])
{
	sortstring(stu,n,coursen);
	int low=0,mid,high=n-1;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(strcmp(x,stu[mid].name)>0)
		{
			low=mid+1;
		}
		else if(strcmp(x,stu[mid].name)<0)
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
void analysis(STUDENT stu[], int n,int coursen)
{
	int  i, j,t,S[N][6];     /* S[]-���鳤��Ϊ6,�������6���ɼ����ε����� */ 
	for(t=0;t<coursen;t++)
	{
			memset(S,0,sizeof(S));
	for (i=0; i<n; i++)
	{
		if (stu[i].score[t] < 60)    
			j = 0;          /* S[]�����±�Ϊ0ʱ, �ǲ�������� */ 
		else
			j = ((int)stu[i].score[t] - 50) / 10;    /* ���ݾ���ɼ�����,ȷ�������ĸ��ɼ����� */ 
		S[t][j]++;         
	} 
	for (j=0; j<6; j++)     /* ��������ε�������������� */  
	{
		if (j == 0)
			printf("< 60    %d  %.2f%%  ", S[t][j], (float)S[t][j]/(float)n*100);
		else if (j == 5)
				printf("   %d  %d  %.2f%%\n", (j+5)*10, S[t][j],	(float)S[t][j]/(float)n*100);
			else
		       	printf("%d--%d  %d  %.2f%%  ", (j+5)*10,(j+5)*10+9,	S[t][j],(float)S[t][j]/(float)n*100);
    }
	}
}
 /*���ѧ�ż��ɼ�*/
 void print(STUDENT stu[],float sumstu[N],float averstu[N],float sumcou[course_N],float avercou[course_N],int n,int coursen)
 {  
    int i,j;
 	for(i=0;i<n;i++)
 	{
	printf("%ld\t%s       ",stu[i].num,stu[i].name);
 	for(j=0;j<coursen;j++)
 	{
 	printf("%.2f\t",stu[i].score[j]);	
	}
	printf("%.2f\t%.2f\n",sumstu[i],averstu[i]);
    }
	printf("sumofcourse\t");
	for(j=0;j<coursen;j++)
	{
		printf("%.2f\t",sumcou[j]);
    }
    printf("\naverofcourse\t");
    for(j=0;j<coursen;j++)
    {
    	printf("%.2f\t",avercou[j]);
	}
	printf("\n");
}

 
