#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 5 


//�������Ϣ����Ϊһ���ṹ�壬����������ƺ����� 
typedef struct footballteam
{
	char name[max_len];
	int data[6];
}TEAM;

int p[6],n;//��������ݺ���Ӹ��� 
char x[max_len];//������������ 
TEAM t[15];

//�������� 
void readdata(TEAM t[15]);

//������������ݣ��������� 
int Sum(TEAM t[15],int sum[15]);

//��������������ֵ 
void swap(int*x,int*y);

//���������ַ��� 
void charswap(char x[],char y[]);

//����Ӱ����ֹ���������� 
void datasort(TEAM t[15]);

//�����������ĸ˳������ 
void sortstring(TEAM t[15]);

//����ĳ����� 
int namesearch(TEAM t[15],char x[max_len],int p[6]);

//��������������� 
void printfdata(TEAM t[15]);

//����������ٴ���� 
void printflater(TEAM t[15]);


int main()
{
	int i,j;
	char k;
	
	printf("please input the number of the footballteams:");
	scanf("%d",&n);
	readdata(t);
	printfdata(t);
	while(1)//��ѭ�� 
	{
	printf("if there are more teams,please input y:");//����ѡ���Ƿ�������룬ֱ�����벻Ϊyʱ���� 
	scanf("%s",&k);
	if(k == 'y')
	{
		printf(" please input the name all win equ lose GF GA:");
		scanf("%s",&x);
		for(j = 0;j < 6;j++)
		{
			scanf("%d",&p[j]);
		}
		printflater(t);
	}
	else break;
	}
	return 0;
	
}


/*�������ܣ���������
  ����������������� t
  ��������ֵ���� 
*/ 
void readdata(TEAM t[15])
{
	int i,j;
	for(i = 0;i < n;i++)
	{
		printf("please input the name all win equ lose GF GA:");
		scanf("%s",t[i].name);
		for(j = 0;j < 6;j++)
		{
		 
		 	scanf("%d",&t[i].data[j]);
		}
	}
}


/*�������ܣ�������������������ӵĻ��� 
  ��������������t�ͻ�������sum
  ��������ֵ���� 
*/ 
int Sum(TEAM t[15],int sum[15])
{
	int i;
	for(i = 0;i < n;i++)
	{
		sum[i] = 0;
		sum[i] = sum[i] + t[i].data[1]*3 + t[i].data[2];
	}
}


/*��������������*/ 
void swap(int*x,int*y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}


//���������ַ��� 
void charswap(char x[],char y[])
{
	char temp2[max_len];
	strcpy(temp2,x);
	strcpy(x,y);
	strcpy(y,temp2);
}


/*�������ܣ�����Ӱ����ֹ����������
  ��������������t��sum,�Լ���������i,j
  ��������ֵ����
*/ 
void datasort(TEAM t[15])
{
	int i,j,k,m,sum[15];
	for(i = 0;i < n-1;i++)
	{
		k = i;
		for(j = i+1;j < n;j++)
		if(sum[j] > sum[k])
		k = j;
		else if(sum[j] == sum[k])
		{
			if((t[j].data[4] - t[j].data[5]) > (t[k].data[4] - t[k].data[5]))
			k = j;
			else if((t[j].data[4] - t[j].data[5]) == (t[k].data[4] - t[k].data[5]))
			{
				if(t[j].data[4] > t[k].data[4])
				k = j;
			}
		}
	if(k != i)
	{
		for(m = 0;m < 6;m++)
		swap(&t[k].data[m],&t[i].data[m]);
	}
	swap(&sum[k],&sum[i]);
	charswap(t[k].name,t[i].name);
	}
}


/*�������ܣ�����Ӱ����������ĸ˳���������
  �����������������t��sum
  ��������ֵ����
*/ 
void sortstring(TEAM t[15])
{
	int i,j,m,sum[15];
	Sum(t,sum);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(t[j].name,t[i].name)<0)
			{
				for(m = 0;m < 6;m++)
				swap(&t[j].data[m],&t[i].data[m]);
				swap(&sum[j],&sum[i]);
				charswap(t[j].name,t[i].name);
			}
		}
	}
}


/*�������ܣ��������ֲ���ĳ֧���
  ����������t������������������
  ��������ֵ����
*/ 
int namesearch(TEAM t[15],char x[max_len],int p[6])
{
	sortstring(t);
	int low=0,mid,high=n-1;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(strcmp(x,t[mid].name)>0)
		{
			low=mid+1;
		}
		else if(strcmp(x,t[mid].name)<0)
	{
		high=mid-1;
	}
	    else 
	    return mid;
	}
	return -1;
}


//������������� 
void printfdata(TEAM t[15])
{
	int i,j,k,m,sum[15];
	Sum(t,sum);
    datasort(t);
	printf("name\tall\twin\tequ\tlose\tGF\tGA\tsum\trank\n");
	for(i = 0;i < n;i++)
	{
		printf("%s\t",t[i].name);
		for(j = 0;j < 6;j++)
		{
		printf("%d\t",t[i].data[j]);
		}
		printf("%d\t",sum[i]);
		printf("%d\n",i+1);
	}
}


/*�������ܣ����������������½������в����
  ��������������t�Լ����������
  ��������ֵ����
*/
void printflater(TEAM t[15])
{
	int i,j,sum[15],l,q = n,k,m; 
	l = namesearch(t,x,p);
	if(l != -1)
	{
		for(i = 0;i < 6;i++)
		t[l].data[i] = t[l].data[i] + p[i];
    Sum(t,sum);
	datasort(t);
	printf("name\tall\twin\tequ\tlose\tGF\tGA\tsum\trank\n");
	for(i = 0;i < q;i++)
	{
		printf("%s\t",t[i].name);
		for(j = 0;j < 6;j++)
		{
		printf("%d\t",t[i].data[j]);
		}
		printf("%d\t",sum[i]);
		printf("%d\n",i+1);
	}
    }
    else
    {
    	strcpy(t[n].name,x);
    	for(i = 0;i < 6;i++)
    	t[n].data[i] = p[i];
    for(i = 0;i < n+1;i++)
	{
		sum[i] = 0;
		sum[i] = sum[i] + t[i].data[1]*3 + t[i].data[2];
	}
	for(i = 0;i < n;i++)
	{
		k = i;
		for(j = i+1;j < n+1;j++)
		if(sum[j] > sum[k])
		k = j;
		else if(sum[j] == sum[k])
		{
			if((t[j].data[4] - t[j].data[5]) > (t[k].data[4] - t[k].data[5]))
			k = j;
			else if((t[j].data[4] - t[j].data[5]) == (t[k].data[4] - t[k].data[5]))
			{
				if(t[j].data[4] > t[k].data[4])
				k = j;
			}
		}
	if(k != i)
	{
		for(m = 0;m < 6;m++)
		swap(&t[k].data[m],&t[i].data[m]);
	}
	swap(&sum[k],&sum[i]);
	charswap(t[k].name,t[i].name);
	}
	printf("name\tall\twin\tequ\tlose\tGF\tGA\tsum\trank\n");
	for(i = 0;i < q+1;i++)
	{
		printf("%s\t",t[i].name);
		for(j = 0;j < 6;j++)
		{
		printf("%d\t",t[i].data[j]);
		}
		printf("%d\t",sum[i]);
		printf("%d\n",i+1);
	}
    }
}



