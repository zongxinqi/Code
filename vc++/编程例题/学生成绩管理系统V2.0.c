#include <stdio.h>
#define N 40                                              /*ͳ��ѧ�����������*/
int menu(void);                                           /*�˵�����*/ 
int readscore(float score[],long num[]);                  /*����ɼ���ѧ��*/ 
float average(float score[],int n);                       /*��ɼ���ƽ��ֵ*/
float sumscore(float score[],int n);                      /*�Գɼ����*/ 
void scoresort(float score[],long num[],int n);           /*���ɼ���������*/
void selectionsort(float a[],int n,float (*compare)(float a,float b));
float ascending(float a,float b);
void swap(float*x,float*y);                               /*���ɼ���������*/ 
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
		    case 4:selectionsort(score,n,ascending);
		           printf("data items in ascending order\n");
		    case 5:numsort(score,num,n);
		           print(score,num,n);
		           break;
		    case 6:printf("please input the number to search:\n");
		           scanf("%ld",&x1);
		           flag=search(score,num,n,x1);
		           printf("%.2f,%ld\n",score[flag],num[flag]);
		           if(flag<0)  printf("not found\n");
		           break;
		    case 7:analysis(score,n);
		           break;
		    case 8:numsort(score,num,n);
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
        printf("4. Sort in ascending order by score \n");
        printf("5. Sort in ascending order by number \n");
	    printf("6. Search by number \n");
        printf("7. Statistic analysis \n");
	    printf("8. List record \n");
        printf("0. Exit \n");
        printf("please enter your choice:\n");
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
/*���ɼ�����������*/ 
void selectionsort(float a[],int n,float (*compare)(float a,float b))
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
		if(k!=i) swap(&a[k],&a[i]);
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
/*���ɼ���������*/ 
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
 void print(float score[],long num[],int n)
 {  
    int i;
 	for(i=0;i<n;i++)
 	printf("%.2f,%ld\n",score[i],num[i]);
 }

 
