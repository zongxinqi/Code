#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 5                                                                /*字符串的最大长度*/
#define N 30                                                                     /*统计学生的最大人数*/
#define course_N 6                                                               /*考试科目数*/
int menu(void);                                                                  /*菜单函数*/ 
void readscore(float score[][course_N],long num[],char name[][max_len],int n);                   /*输入成绩和学号和姓名*/ 
float averagestu(float score[][course_N],float sumstu[N],float averstu[N],int n);                                              /*求成绩的平均值*/
float sumscorestu(float score[][course_N],float sumstu[N],int n);
float sumscorecou(float score[][course_N],float sumcou [N],int n);
float averagecou(float score[][course_N],float sumcou[course_N],float avercou[course_N],int n);
void scoresort(float score[][course_N],float sumstu[N],float averstu[N],long num[],char name[][max_len],int n);             /*按成绩降序排列*/
void selectionsort(float score[][course_N],float sumstu[N],float averstu[N],int n,long num[],char name [][max_len],float (*compare)(float a,float b));
float ascending(float a,float b);
void swap(float*x,float*y);
void longswap(long *x,long *y);
void charswap(char x[],char y[]);                                                      /*按成绩升序排列*/ 
void sortstring(float score[][course_N],long num[],char name[][max_len],int n);                                     /*按姓名的字典顺序输出*/
void numsort(float score[][course_N],long num[],char name[N][max_len],int n);              /*按学号升序排列*/ 
int search(float score[][course_N],long num[],char name[][max_len],int n,long x1);         /*通过学号进行查找*/
int namesearch(float score[][course_N],long num[],char name[][max_len],int n,char x[max_len]);     /*按姓名进行查找*/
void analysis(float score[][course_N],int n);                                              /*成绩分析*/ 
void print(float score[][course_N],float sumstu[N],float averstu[N],float sumcou[course_N],float avercou[course_N],long num[],char name[][max_len],int n);                 /*输出学生的成绩和学号*/ 
int main()
{
	int cho,n,flag1,flag2,i,j;                                                              /*定义整形变量输入选项和学生人数和查找后的返回值*/
	float sumstu[N],averstu[N],sumcou[course_N],avercou[course_N],score[N][course_N];                                                     /*定义实型的总和，平均值和学生成绩*/
	long num[N],x1;                                                              /*定义长整型的学号和要查找的号码*/ 
	char name[N][max_len],x[max_len];                                                       /*定义姓名的二维数组*/
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
/*定义菜单函数并输入选项值，无参数 */
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
/*输入学生的学号和成绩，并返回学生的人数*/
void readscore(float score[][course_N],long num[],char name[][max_len],int n) 
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<course_N;j++)
		{
			scanf("%f",&score[i][j]);                            /*输入每个学生的各门课成绩*/
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
/*学生成绩的加和*/
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
/*求学生成绩的平均值*/
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
/*将成绩按升序排列*/ 
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
/*按成绩降序排序*/ 
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
/*按学号升序排列*/
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
                k = j;    /*记录最小学号的下标位置*/
            }
        }
        if (k != i)       /*若最小学号不在下标位置i*/
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
/*将姓名按字典顺序排序*/
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
/*按学号查找*/
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
/*通过姓名进行查找*/
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
/*求出各分数段所占比例*/
void analysis(float score[][course_N], int n)
{
	int  i, j,t,stu[N][6];     /* stu[]-数组长度为6,用来存放6个成绩区段的人数 */ 
	for(t=0;t<course_N;t++)
	{
			memset(stu,0,sizeof(stu));
	for (i=0; i<n; i++)
	{
		if (score[i][t] < 60)    
			j = 0;          /* stu[]数组下标为0时, 是不及格情况 */ 
		else
			j = ((int)score[i][t] - 50) / 10;    /* 根据具体成绩计算,确定属于哪个成绩区段 */ 
		stu[t][j]++;         
	} 
	for (j=0; j<6; j++)     /* 计算各区段的人数比例并输出 */  
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
 /*输出学号及成绩*/
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

 
