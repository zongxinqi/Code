#include  <stdio.h>
#define ARR_SIZE 30                               /* 最多可处理30人的学号和成绩 */
int	Menu(void);                                   /* 显示系统功能菜单 */
int	ReadScore(long num[], float score[]);         /* 输入学号和成绩 */
float GetAver(float score[], int n);              /* 计算课程平均分 */
float GetSum(float score[], int n);                /* 计算课程总分 */
void Dsortbyscore(long num[],float score[],int n);  /* 按成绩由高到低降序排序 */
void Asortbynum(long num[],float score[],int n);    /* 按学号由低到高升序排序 */ 
void Print(long num[],float score[],int n);         /* 输出所有学生的学号和成绩 */ 
int Search(long num[], float score[], int n, long x);  /* 按学号顺序查找,并输出成绩和成绩排名 */ 
void GetDetail(float score[], int n);                 /* 成绩统计分析，给出各成绩区段上的人数和比例 */ 

int main()
{
	int item,n,flag;       /* item-用户输入的功能选项，n-实际学生人数，flag-查找函数的返回值 */
	float score[ARR_SIZE],Aver,Sum;   /* score[]-成绩数组，Aver-成绩平均值，Sum-成绩总和 */
	long num[ARR_SIZE],xnum;    /* num[]-学号数组，xnum-要查找的学号 */

	while(1)
	{
		item=Menu();
		switch(item)
		{
	  	  case 1:  printf("Please enter num and score until score<0:\n");
	               n = ReadScore(num, score);            /* 输入学生的学号和成绩 */ 
                   printf("Total students:%d\n", n);
                   Print(num,score,n);          /* 输出学生的学号和成绩，检验输入数据是否正确 */ 
			       break;
          case 2:  Sum = GetSum(score, n); 
			       printf("Sum= %.2f\n", Sum);   /* 计算成绩总和并输出 */ 
                   Aver = GetAver(score, n); 
				   printf("Aver=%.2f\n", Aver);   /* 计算成绩平均值并输出 */ 
			       break;
		  case 3:  Dsortbyscore(num,score,n);     /* 按成绩由高到低降序排序 */
	               printf("Descending sort by score :\n"); 
				   Print(num,score,n);            /* 输出排序后的结果 */
			       break;
		  case 4:  Asortbynum(num,score,n);       /* 按学号由低到高升序排序 */ 
	               printf("Ascending sort by number :\n"); 
				   Print(num,score,n);            /* 输出排序后的结果 */
			       break; 
          case 5:  printf("Searching...Input xnum:");  
	               scanf("%ld",&xnum);            /* 输入要查找的学号 */
                   flag=Search(num, score, n, xnum);   /* 调用查找函数并返回是否找到的标志 */
                   if(flag<0)  printf("Not found!\n");
			       break; 
          case 6:  GetDetail(score, n);	    /* 成绩统计分析，给出各成绩区段上的人数和比例 */ 
			       break; 
	      case 7:  Asortbynum(num,score,n);           /* 输出之前先按学号升序排序 */ 
			       Print(num,score,n);                /* 输出所有学生的学号和成绩 */ 
			       break; 
		  case 0:  printf("End of program! \n");
			       exit(0);                 /* 退出程序 */
		  default: printf("Input error! \n");
		}
	}
    return 0;	
}


/* 函数0
   函数功能：从键盘输入操作选项
   函数参数：无参数
   函数返回值：操作选项值
*/
int Menu(void)
{
	int item;
	
	printf("\nManagement for student scores \n");
        printf("1. Input record \n");
        printf("2. Caculate total and average of course \n");
	    printf("3. Sort in descending order by score \n");
        printf("4. Sort in ascending order by number \n");
	    printf("5. Search by number \n");
        printf("6. Statistic analysis \n");
	    printf("7. List record \n");
        printf("0. Exit \n");
        printf("Please enter your choice(0-7): ");
        scanf("%d", &item);
        return(item);
}


/* 函数1
   函数功能：从键盘输入某班学生的学号和某课程成绩，当输入成绩为负值时，输入结束
   函数参数：长整型数组num，存放学生学号；单精度实型数组score，存放学生成绩
   函数返回值：学生总数
*/
int ReadScore(long num[], float score[])
{
	int i = 0;

	scanf("%ld%f", &num[i], &score[i]);

	while (score[i] >= 0)
	{
		i++;
		scanf("%ld%f", &num[i], &score[i]);
	}
	return i;
}


/* 函数2-1
   函数功能：计算课程总分
   函数参数：单精度实型数组score，存放学生成绩；整型变量n，存放学生总数
   函数返回值：课程总分
*/
float GetSum(float score[], int n)
{   
	int i;
    float  sum = 0;

	for (i=0; i<n; i++)
	  sum = sum + score[i];
	
	return sum;
} 


/* 函数2-2
   函数功能：计算平均分
   函数参数：实型数组score，存放学生成绩；整型变量n，存放学生总数
   函数返回值：平均分
*/
float GetAver(float score[], int n)
{
	int    i;
	float  sum = 0;

	for (i=0; i<n; i++)
		sum = sum + score[i];
	
	return sum/n;
} 


/* 函数3
   函数功能：按总分成绩由高到低降序排出成绩的名次
   函数参数：长整型数组num，存放学生学号；单精度实型数组score，存放学生成绩；
			 整型变量n，存放学生人数
   函数返回值：无
*/
void Dsortbyscore(long num[],float score[], int n)
{
	int i, j, k, m;
	float temp1;
	long temp2;
	
	for (i=0; i<n-1; i++)
	{
		k = i;
		for (j=i+1; j<n; j++)
			if (score[j] > score[k])  
				k = j;
		
		if (k != i)
		{
			temp1 = score[k];  score[k] = score[i];  score[i] = temp1;
			temp2 = num[k];  num[k] = num[i];  num[i] = temp2;
		}
	}
}



/* 函数4
   函数功能：按学号由低到高升序排序
   函数参数：长整型数组num，存放学生学号；单精度实型数组score，存放学生成绩；
			 整型变量n，存放学生人数
   函数返回值：无
*/
void Asortbynum(long num[],float score[], int n)
{
	int i, j, k, m;
	float temp1;
	long temp2;
	
	for (i=0; i<n-1; i++)
	{
		k = i;
		for (j=i+1; j<n; j++)
			if (num[j] < num[k])  k = j;
		
		if (k != i)
		{
			temp2 = num[k];  num[k] = num[i];  num[i] = temp2;	
			temp1 = score[k];  score[k] = score[i];  score[i] = temp1;
		}
	}
}


/* 函数5
   函数功能：在学号数组中顺序查找学生的学号
   函数参数：长整型数组num，存放学生学号；单精度实型数组score，存放学生成绩；
             整型变量n，存放学生人数；长整型变量x，存放待查找学生的学号
   函数返回值：找到时，输出学生学号、成绩和成绩排名，并返回该数组元素下标；
               没找到，返回-1
*/
int Search(long num[], float score[], int n, long x)
{
	int  i;

	Dsortbyscore(num, score, n);         /* 为了给出排名先按成绩由高到低重新排序 */ 
	for (i=0; i<n; i++)
	{
		if (num[i] == x)  
		{ printf("Num_%ld:%.2f  No.%d\n",x,score[i],i+1);
		  return(i);
		}
	}
	return (-1);
}


/* 函数6
   函数功能：统计各分数段的学生人数及所占的百分比
   函数参数：单精度实型数组score，存放学生成绩；整型变量n，存放学生总数
   函数返回值：无
*/
void GetDetail(float score[], int n)
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


/* 函数7
   函数功能： 打印学生学号和成绩
   函数参数： 长整型数组num，存放学生学号；单精度实型数组score，存放学生成绩；
			  整型变量n，存放学生人数
   函数返回值：无
*/
void Print(long num[], float score[], int n)
{
	int  i;

	printf("   NO \t|  score \n");
	printf("----------------------------------------------------\n");
	for (i=0; i<n; i++)
	  printf("%6ld\t|  %.2f \n", num[i],score[i]);
}

