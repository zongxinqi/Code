#include <stdio.h>
#include <string.h>
#define max_len 5                                                                /*字符串的最大长度*/
#define N 30                                                                     /*统计学生的最大人数*/
int menu(void);                                                                  /*菜单函数*/ 
void readscore(float score[],long num[],char name[][max_len],int n);                   /*输入成绩和学号和姓名*/ 
float average(float score[],int n);                                              /*求成绩的平均值*/
float sumscore(float score[],int n);                                             /*对成绩求和*/ 
void scoresort(float score[],long num[],char name[][max_len],int n);             /*按成绩降序排列*/
void selectionsort(float a[],int n,long num[],char name [][max_len],float (*compare)(float a,float b));
float ascending(float a,float b);
void swap(float*x,float*y);
void longswap(long *x,long *y);
void charswap(char x[],char y[]);                                                      /*按成绩升序排列*/ 
void sortstring(float score[],long num[],char name[][max_len],int n);                                     /*按姓名的字典顺序输出*/
void numsort(float score[],long num[],char name[N][max_len],int n);              /*按学号升序排列*/ 
int search(float score[],long num[],char name[][max_len],int n,long x1);         /*通过学号进行查找*/
int namesearch(float score[],long num[],char name[][max_len],int n,char x[max_len]);     /*按姓名进行查找*/
void analysis(float score[],int n);                                              /*成绩分析*/ 
void print(float score[],long num[],char name[][max_len],int n);                 /*输出学生的成绩和学号*/ 
int main()
{
	int cho,n,flag1,flag2;                                                              /*定义整形变量输入选项和学生人数和查找后的返回值*/
	float sum,aver,score[N];                                                     /*定义实型的总和，平均值和学生成绩*/
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
/*定义菜单函数并输入选项值，无参数 */
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
/*输入学生的学号和成绩，并返回学生的人数*/
void readscore(float score[],long num[],char name[][max_len],int n) 
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%f,%ld,%s", &score[i], &num[i],name[i]);
	}
}
/*学生成绩的加和*/
float sumscore(float score[],int n)
{
 int i,sum=0;
  for(i=0;i<n;i++)	
  {
  	sum=sum+score[i];
  }
  return sum;
}
/*求学生成绩的平均值*/
float average(float score[],int n)
{
  int i,sum=0;
  for(i=0;i<n;i++)	
  {
  	sum=sum+score[i];
  }	
  return sum/n;
}
/*将成绩按升序排列*/ 
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
/*按成绩降序排序*/ 
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
/*按学号升序排列*/
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
                k = j;    /*记录最小学号的下标位置*/
            }
        }
        if (k != i)       /*若最小学号不在下标位置i*/
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
/*按姓名的首字母排序*/
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
/*按学号查找*/
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
/*通过姓名进行查找*/
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
/*求出各分数段所占比例*/
void analysis(float score[], int n)
{
	int  i, j, stu[6];     /* stu[]-数组长度为6,用来存放6个成绩区段的人数 */ 
	for (i=0; i<6; i++)
		stu[i]=0;
	for (i=0; i<n; i++)
	{
		if (score[i] < 60)    
			j = 0;          /* stu[]数组下标为0时, 是不及格情况 */ 
		else
			j = ((int)score[i] - 50) / 10;    /* 根据具体成绩计算,确定属于哪个成绩区段 */ 
		stu[j]++;          /* 在相应的成绩区段上将人数增1 */  
	}
	for (i=0; i<6; i++)     /* 计算各区段的人数比例并输出 */  
	{
		if (i == 0)
			printf("< 60    %d  %.2f%%\n", stu[i], (float)stu[i]/(float)n*100);
		else if (i == 5)
				printf("   %d  %d  %.2f%%\n", (i+5)*10, stu[i],	(float)stu[i]/(float)n*100);
			else
		       	printf("%d--%d  %d  %.2f%%\n", (i+5)*10,(i+5)*10+9,	stu[i],(float)stu[i]/(float)n*100);
	}
}
 /*输出学号及成绩*/
 void print(float score[],long num[],char name[][max_len],int n)
 {  
    int i;
 	for(i=0;i<n;i++)
 	printf("%.2f,%ld,%s\n",score[i],num[i],name[i]);
 }

 
