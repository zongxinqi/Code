#include <stdio.h>
#define N 40                                              /*ͳ��ѧ�����������*/
int menu(void);                                           /*�˵�����*/ 
int readscore(float score[],long num[]);                  /*����ɼ���ѧ��*/ 
float average(float score[],int n);                       /*��ɼ���ƽ��ֵ*/ 
float sumscore(float score[],int n);                           /*�Գɼ����*/ 
void scoresort(float score[],long num[],int n);           /*���ɼ���������*/ 
void numsort(float score[],long num[],int n);             /*��ѧ����������*/ 
int search(float score[],long num[],int n,long x);        /*ͨ��ѧ�Ž��в���*/
void analysis(float score[],int n);                       /*�ɼ�����*/ 
void print(float score[],long num[],int n);               /*���ѧ���ĳɼ���ѧ��*/ 
int main()
{
	int cho,n,flag;                                       /*�������α�������ѡ���ѧ�������Ͳ��Һ�ķ���ֵ*/
	float sum,aver,score[N];                               /*����ʵ�͵��ܺͣ�ƽ��ֵ��ѧ���ɼ�*/
	long num[N],x1;                                        /*���峤���͵�ѧ�ź�Ҫ���ҵĺ���*/ 
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
/*����˵�����������ѡ��ֵ���޲��� */
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
/*����ѧ����ѧ�źͳɼ���������ѧ��������*/
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
/*���ɼ�����*/ 
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
/*��ѧ����������*/
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
        }  
    }
}
/*��ѧ�Ų���*/
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
/*�������������ռ����*/
void analysis(float score[],int n)
{
int  i, j, stu[2];     
	for (i=0; i<2; i++)
		stu[i]=0;
	for (i=0; i<n; i++)
	{
		if (score[i] < 60)    
			j = 0;          /* stu[]�����±�Ϊ0ʱ, �ǲ�������� */ 
		else
		   j=1;
		stu[j]++;          
	}
	for (i=0; i<2; i++)     /* ��������ε�������������� */  
	{
		if (i == 0)
			printf("< 60    %d  %.2f%%\n",stu[i], (float)stu[i]/(float)n*100);
		else 
			printf("> 60    %d  %.2f%%\n", stu[i],	(float)stu[i]/(float)n*100);
	
	}
 }
 /*���ѧ�ż��ɼ�*/
 void print(float score[],long num[],int n)
 {  
    int i;
 	for(i=0;i<n;i++)
 	printf("%.2f,%ld\n",score[i],num[i]);
 }

 
