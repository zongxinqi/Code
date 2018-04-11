#include <stdio.h>
#define N 40                                              /*统计学生的最大人数*/
int menu(void);                                           /*菜单函数*/ 
int readscore(float score[],long num[]);                  /*输入成绩和学好*/ 
float average(float score[],int n);                       /*求成绩的平均值*/ 
float sumscore(float score[],int n);                           /*对成绩求和*/ 
void scoresort(float score[],long num[],int n);           /*按成绩降序排列*/ 
void numsort(float score[],long num[],int n);             /*按学号升序排列*/ 
int search(float score[],long num[],int n,long x);        /*通过学号进行查找*/
void analysis(float score[],int n);                       /*成绩分析*/ 
void print(float score[],long num[],int n);               /*输出学生的成绩和学号*/ 
int main()
{
	int cho,n,flag;                                       /*定义整形变量输入选项和学生人数和查找后的返回值*/
	float sum,aver,score[N];                               /*定义实型的总和，平均值和学生成绩*/
	long num[N],x1;                                        /*定义长整型的学号和要查找的号码*/ 
	while(1)
	{
		cho=menu();
		switch(cho)
		{
			case 0:printf("End of program! \n");
			       exit(0);            
		    case 1:printf("please input score and number:\n");
		           n=readscore(score,num);
		           printf("total students are %d\n",n);
		           print(score,num,n);
		           break;
		    case 2:sum=sumscore(score,n);
		           printf("sum=%f\n",sum);
		           aver=average(score,n);
		           printf("average=%f\n",aver);
		           break;
		    case 3:scoresort(score,num,n);
		           print(score,num,n);
		           break;
		    case 4:numsort(score,num,n);
		           print(score,num,n);
		           break;
		    case 5:printf("please input the number to search:\n");
		           scanf("%ld",&x1);
		           flag=search(score,num,n,x1);
		           printf("%.2f,%ld\n",score[flag],num[flag]);
		           if(flag<0)  printf("not found\n");
		           break;
		    case 6:analysis(score,n);
		           break;
		    case 7:numsort(score,num,n);
		           print(score,num,n);
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
        printf("4. Sort in ascending order by number \n");
	    printf("5. Search by number \n");
        printf("6. Statistic analysis \n");
	    printf("7. List record \n");
        printf("0. Exit \n");
        printf("please choose the item\n");
        scanf("%d",&cho);
        return(cho);
}
/*输入学生的学号和成绩，并返回学生的人数*/
int readscore(float score[],long num[]) 
{
	int i=0;
	printf("please input data:\n");
	
	scanf("%ld,%f", &num[i], &score[i]);

	while (score[i] >= 0)
	{
		i++;
		scanf("%ld,%f", &num[i], &score[i]);
	}
	return i;
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
/*按成绩排序*/ 
void scoresort(float score[],long num[],int n)
{
	int i, j, k, temp1;
    long temp2;
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
            temp1 = score[k];
            score[k] = score[i];
            score[i] = temp1; 
            temp2 = num[k]; 
            num[k] = num[i]; 
            num[i] = temp2;
        }  
    }
}
/*按学号升序排列*/
void numsort(float score[],long num[],int n)
{
  int i, j, k, temp1;
    long temp2;	
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
        }  
    }
}
/*按学号查找*/
int search(float score[],long num[],int n,long x)
{
int  low, high, mid;
	low = 0;  
	high = n - 1;              
	while (low <= high)
	{
   	mid = (high + low) / 2; 
		if (x > num[mid])   
   	{
			low = mid + 1; 
   	}
		else  if (x < num[mid])  
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
/*求出各分数段所占比例*/
void analysis(float score[],int n)
{
int  i, j, stu[2];     
	for (i=0; i<2; i++)
		stu[i]=0;
	for (i=0; i<n; i++)
	{
		if (score[i] < 60)    
			j = 0;          /* stu[]数组下标为0时, 是不及格情况 */ 
		else
		   j=1;
		stu[j]++;          
	}
	for (i=0; i<2; i++)     /* 计算各区段的人数比例并输出 */  
	{
		if (i == 0)
			printf("< 60    %d  %.2f%%\n",stu[i], (float)stu[i]/(float)n*100);
		else 
			printf("> 60    %d  %.2f%%\n", stu[i],	(float)stu[i]/(float)n*100);
	
	}
 }
 /*输出学号及成绩*/
 void print(float score[],long num[],int n)
 {  
    int i;
 	for(i=0;i<n;i++)
 	printf("%.2f,%ld\n",score[i],num[i]);
 }

 
