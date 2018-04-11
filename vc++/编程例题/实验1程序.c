#include  <stdio.h>
#define ARR_SIZE 30                               /* ���ɴ���30�˵�ѧ�źͳɼ� */
int	Menu(void);                                   /* ��ʾϵͳ���ܲ˵� */
int	ReadScore(long num[], float score[]);         /* ����ѧ�źͳɼ� */
float GetAver(float score[], int n);              /* ����γ�ƽ���� */
float GetSum(float score[], int n);                /* ����γ��ܷ� */
void Dsortbyscore(long num[],float score[],int n);  /* ���ɼ��ɸߵ��ͽ������� */
void Asortbynum(long num[],float score[],int n);    /* ��ѧ���ɵ͵����������� */ 
void Print(long num[],float score[],int n);         /* �������ѧ����ѧ�źͳɼ� */ 
int Search(long num[], float score[], int n, long x);  /* ��ѧ��˳�����,������ɼ��ͳɼ����� */ 
void GetDetail(float score[], int n);                 /* �ɼ�ͳ�Ʒ������������ɼ������ϵ������ͱ��� */ 

int main()
{
	int item,n,flag;       /* item-�û�����Ĺ���ѡ�n-ʵ��ѧ��������flag-���Һ����ķ���ֵ */
	float score[ARR_SIZE],Aver,Sum;   /* score[]-�ɼ����飬Aver-�ɼ�ƽ��ֵ��Sum-�ɼ��ܺ� */
	long num[ARR_SIZE],xnum;    /* num[]-ѧ�����飬xnum-Ҫ���ҵ�ѧ�� */

	while(1)
	{
		item=Menu();
		switch(item)
		{
	  	  case 1:  printf("Please enter num and score until score<0:\n");
	               n = ReadScore(num, score);            /* ����ѧ����ѧ�źͳɼ� */ 
                   printf("Total students:%d\n", n);
                   Print(num,score,n);          /* ���ѧ����ѧ�źͳɼ����������������Ƿ���ȷ */ 
			       break;
          case 2:  Sum = GetSum(score, n); 
			       printf("Sum= %.2f\n", Sum);   /* ����ɼ��ܺͲ���� */ 
                   Aver = GetAver(score, n); 
				   printf("Aver=%.2f\n", Aver);   /* ����ɼ�ƽ��ֵ����� */ 
			       break;
		  case 3:  Dsortbyscore(num,score,n);     /* ���ɼ��ɸߵ��ͽ������� */
	               printf("Descending sort by score :\n"); 
				   Print(num,score,n);            /* ��������Ľ�� */
			       break;
		  case 4:  Asortbynum(num,score,n);       /* ��ѧ���ɵ͵����������� */ 
	               printf("Ascending sort by number :\n"); 
				   Print(num,score,n);            /* ��������Ľ�� */
			       break; 
          case 5:  printf("Searching...Input xnum:");  
	               scanf("%ld",&xnum);            /* ����Ҫ���ҵ�ѧ�� */
                   flag=Search(num, score, n, xnum);   /* ���ò��Һ����������Ƿ��ҵ��ı�־ */
                   if(flag<0)  printf("Not found!\n");
			       break; 
          case 6:  GetDetail(score, n);	    /* �ɼ�ͳ�Ʒ������������ɼ������ϵ������ͱ��� */ 
			       break; 
	      case 7:  Asortbynum(num,score,n);           /* ���֮ǰ�Ȱ�ѧ���������� */ 
			       Print(num,score,n);                /* �������ѧ����ѧ�źͳɼ� */ 
			       break; 
		  case 0:  printf("End of program! \n");
			       exit(0);                 /* �˳����� */
		  default: printf("Input error! \n");
		}
	}
    return 0;	
}


/* ����0
   �������ܣ��Ӽ����������ѡ��
   �����������޲���
   ��������ֵ������ѡ��ֵ
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


/* ����1
   �������ܣ��Ӽ�������ĳ��ѧ����ѧ�ź�ĳ�γ̳ɼ���������ɼ�Ϊ��ֵʱ���������
   ��������������������num�����ѧ��ѧ�ţ�������ʵ������score�����ѧ���ɼ�
   ��������ֵ��ѧ������
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


/* ����2-1
   �������ܣ�����γ��ܷ�
   ����������������ʵ������score�����ѧ���ɼ������ͱ���n�����ѧ������
   ��������ֵ���γ��ܷ�
*/
float GetSum(float score[], int n)
{   
	int i;
    float  sum = 0;

	for (i=0; i<n; i++)
	  sum = sum + score[i];
	
	return sum;
} 


/* ����2-2
   �������ܣ�����ƽ����
   ����������ʵ������score�����ѧ���ɼ������ͱ���n�����ѧ������
   ��������ֵ��ƽ����
*/
float GetAver(float score[], int n)
{
	int    i;
	float  sum = 0;

	for (i=0; i<n; i++)
		sum = sum + score[i];
	
	return sum/n;
} 


/* ����3
   �������ܣ����ֳܷɼ��ɸߵ��ͽ����ų��ɼ�������
   ��������������������num�����ѧ��ѧ�ţ�������ʵ������score�����ѧ���ɼ���
			 ���ͱ���n�����ѧ������
   ��������ֵ����
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



/* ����4
   �������ܣ���ѧ���ɵ͵�����������
   ��������������������num�����ѧ��ѧ�ţ�������ʵ������score�����ѧ���ɼ���
			 ���ͱ���n�����ѧ������
   ��������ֵ����
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


/* ����5
   �������ܣ���ѧ��������˳�����ѧ����ѧ��
   ��������������������num�����ѧ��ѧ�ţ�������ʵ������score�����ѧ���ɼ���
             ���ͱ���n�����ѧ�������������ͱ���x����Ŵ�����ѧ����ѧ��
   ��������ֵ���ҵ�ʱ�����ѧ��ѧ�š��ɼ��ͳɼ������������ظ�����Ԫ���±ꣻ
               û�ҵ�������-1
*/
int Search(long num[], float score[], int n, long x)
{
	int  i;

	Dsortbyscore(num, score, n);         /* Ϊ�˸��������Ȱ��ɼ��ɸߵ����������� */ 
	for (i=0; i<n; i++)
	{
		if (num[i] == x)  
		{ printf("Num_%ld:%.2f  No.%d\n",x,score[i],i+1);
		  return(i);
		}
	}
	return (-1);
}


/* ����6
   �������ܣ�ͳ�Ƹ������ε�ѧ����������ռ�İٷֱ�
   ����������������ʵ������score�����ѧ���ɼ������ͱ���n�����ѧ������
   ��������ֵ����
*/
void GetDetail(float score[], int n)
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


/* ����7
   �������ܣ� ��ӡѧ��ѧ�źͳɼ�
   ���������� ����������num�����ѧ��ѧ�ţ�������ʵ������score�����ѧ���ɼ���
			  ���ͱ���n�����ѧ������
   ��������ֵ����
*/
void Print(long num[], float score[], int n)
{
	int  i;

	printf("   NO \t|  score \n");
	printf("----------------------------------------------------\n");
	for (i=0; i<n; i++)
	  printf("%6ld\t|  %.2f \n", num[i],score[i]);
}

