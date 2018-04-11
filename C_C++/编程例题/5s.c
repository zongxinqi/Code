#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 5 


//将球队信息定义为一个结构体，包括球队名称和数据 
typedef struct footballteam
{
	char name[max_len];
	int data[6];
}TEAM;

int p[6],n;//插入的数据和球队个数 
char x[max_len];//插入的球队名称 
TEAM t[15];

//读入数据 
void readdata(TEAM t[15]);

//根据输入的数据，求队伍积分 
int Sum(TEAM t[15],int sum[15]);

//交换两个整数的值 
void swap(int*x,int*y);

//交换两个字符串 
void charswap(char x[],char y[]);

//将球队按积分规则进行排序 
void datasort(TEAM t[15]);

//将球队名按字母顺序排序 
void sortstring(TEAM t[15]);

//查找某个球队 
int namesearch(TEAM t[15],char x[max_len],int p[6]);

//将排序后的数据输出 
void printfdata(TEAM t[15]);

//插入结束后再次输出 
void printflater(TEAM t[15]);


int main()
{
	int i,j;
	char k;
	
	printf("please input the number of the footballteams:");
	scanf("%d",&n);
	readdata(t);
	printfdata(t);
	while(1)//死循环 
	{
	printf("if there are more teams,please input y:");//可以选择是否继续输入，直到输入不为y时结束 
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


/*函数功能：读入数据
  函数参数：球队数组 t
  函数返回值：无 
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


/*函数功能：根据输入的数据求出球队的积分 
  函数参数：数组t和积分数组sum
  函数返回值：无 
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


/*交换两个整型数*/ 
void swap(int*x,int*y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}


//交换两个字符串 
void charswap(char x[],char y[])
{
	char temp2[max_len];
	strcpy(temp2,x);
	strcpy(x,y);
	strcpy(y,temp2);
}


/*函数功能：将球队按积分规则进行排序
  函数参数：数组t和sum,以及计数变量i,j
  函数返回值：无
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


/*函数功能：将球队按球队名的字母顺序进行排列
  函数参数：球队数组t和sum
  函数返回值：无
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


/*函数功能：根据名字查找某支球队
  函数参数：t，插入的球队名和数据
  函数返回值：无
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


//输出排序后的数据 
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


/*函数功能：将插入后的数组重新进行排列并输出
  函数参数：数组t以及插入的数据
  函数返回值：无
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



