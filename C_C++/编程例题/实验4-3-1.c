#include <stdio.h>

#define N 40

void Input(int n);

void Sort(int m,int n);

void Search(int m,int n);

void DataSort(int n);

struct student
{
	char studentID[10];
	
	char studentName[10];
	
	int score[2];
	
	int sum; 
	
	float eaver;
	
	float maver;
	
};

struct student stu[N];

int main()
{
	int n,ch,a,t;
	
	printf("\n请输入学生人数：");
 	
 	scanf("%d",&n);
 	
	Input(n);
	
	printf("\n请输入m的值（0代表计算英语平均成绩，1代表计算数学平均成绩）：",&ch);
	
	scanf("%d",&ch);
	
	Sort(ch,n);
	
	/*printf("\n请输入m的值（0代表计算英语平均成绩，1代表计算数学平均成绩）：",&ch);
	 
	scanf("%d",&ch);
	
	Sort(ch,n);*/ 
	
	system("pause");
	
	printf("\n\n查找所有英语成绩为某个值的学生，请输入英语成绩：");
	
	scanf("%d",&a);
	
	Search(a,n);
	
	system("pause");
	
	DataSort(n);
	
	return 0;
 } 
 
 void Input(int n)
 {	
 	int i,esum,msum;
 	
 	float ll;
 	
 	esum=msum=0;
 	
 	for(i=0;i<n;i++)
 	{
 		printf("\n\n请输入第%d个学生的学号：",i+1);
	
		scanf("%s",&stu[i].studentID);
		
		getchar();
		
		printf("\n请输入第%d个学生的姓名：",i+1);	
		
		scanf("%s",stu[i].studentName);
		
		getchar();
	
		printf("\n请输入第%d个学生的英语成绩：",i+1);
		
		scanf("%d",&stu[i].score[0]);
		
		printf("\n请输入第%d个学生的数学成绩：",i+1);
		
		scanf("%d",&stu[i].score[1]);
	 }
	 
	 for(i=0;i<n;i++)
	 {
	 	stu[i].sum=stu[i].score[0]+stu[i].score[1];
	 	
	 	esum+=stu[i].score[0];
	 	
	 	msum+=stu[i].score[1];
	 }
	 
	 for(i=0;i<n;i++)
	 {
		stu[i].eaver=(float)esum/n;
	
		stu[i].maver=(float)msum/n;
	 }

//	printf("\n\n英语平均分为：%.2f\n",stu[0].eaver);
	
//	printf("\n数学平均分为：%.2f\n\n",stu[0].maver);

	
	
	getchar();

	system("pause");
	
	printf("\n输出所有学生信息：\n");

	for(i=0;i<n;i++)
	{
		ll=(float)stu[i].sum/2;
		
		printf("\n 学生学号：%s",stu[i].studentID);
		
		printf("\n 学生姓名：%s",stu[i].studentName);
		
		printf("\n 英语成绩：%d",stu[i].score[0]);
		
		printf("\n 数学成绩：%d",stu[i].score[1]);
		
		printf("\n   平均分：%.2f\n",ll);
		
		printf("\n   总分  ：%d\n",stu[i].sum);
		
		getchar();
		
	//	system("pause");
	}
}
 
 void Sort(int m,int n)
 {
 	int i;
 	
 	if(m==0)
 	{
		printf("\n英语平均分为：%.2f\n",stu[0].eaver);
 		
 		printf("\n低于英语平均分的学生信息为：\n");
 		
 		for(i=0;i<n;i++)
 		{
 			if(stu[i].score[0]<stu[0].eaver)
 			{
 				printf("\n 学生学号：%s",stu[i].studentID);
		
				printf("\n 学生姓名：%s",stu[i].studentName);
				
				printf("\n 英语成绩：%d",stu[i].score[0]);
				
				printf("\n 数学成绩：%d",stu[i].score[1]);
				
				printf("\n   总分  ：%d\n\n",stu[i].sum);
			 } 
		 }
	 }
	 
	 else if(m==1)
	 {
		printf("\n数学平均分为：%.2f\n",stu[0].maver);
		
	 	printf("\n低于数学平均分的学生信息为：\n");
	 	
	 	for(i=0;i<n;i++)
 		{
 			if(stu[i].score[1]<stu[0].maver)
 			{
 				printf("\n 学生学号：%s",stu[i].studentID);
		
				printf("\n 学生姓名：%s",stu[i].studentName);
				
				printf("\n 英语成绩：%d",stu[i].score[0]);
				
				printf("\n 数学成绩：%d",stu[i].score[1]);
				
				printf("\n   总分  ：%d\n\n",stu[i].sum);
			 }	
		 }
	 }
	 
	 else
	 {
	 	printf("\n n的值为0或1.\n");
	  } 
 }
 
 void Search(int m,int n)
 {
 	int i,j=0;
 	
 	for(i=0;i<n;i++)
 	{
 		if(m==stu[i].score[0])
 		{
			printf("\n英语成绩为%d的学生信息为：\n",m); 
			
			j=1;
			
			break;
		 }
	 }
	 
	if(j==0)
	{
	 	printf("没有该成绩的学生。"); 
	}
	 
	else
	{
	 	for(i=0;i<n;i++)
		{
			if(m==stu[i].score[0])
			{
			 	printf("\n 学生学号：%s",stu[i].studentID);
		
				printf("\n 学生姓名：%s",stu[i].studentName);
				
				printf("\n 英语成绩：%d",stu[i].score[0]);
				
				printf("\n 数学成绩：%d",stu[i].score[1]);
				
				printf("\n   总分  ：%d\n\n",stu[i].sum);	
			}
		} 
	} 
 }
 
void DataSort(int n)
{
	int i,j,k,t,m,p,temp,s[n],c[n];
	
	for(i=0;i<n;i++)
	{
		s[i]=stu[i].sum;
	}
	
	for(i=0;i<n-1;i++)
	{
		k=i;
		
		for(j=i+1;j<n;j++)
		{
			if(s[k]<s[j])
			{
				k=j;
			 } 

		} 
		if(k!=1)
		{
			temp=s[k];
			
			s[k]=s[i];
			
			s[i]=temp;	
		}
	}
	
	j=0;
	
	for(i=0;i<n;i++)
	{
		if(s[i]>s[i+1])
		{
			c[j]=s[i];
		}
		else
		{
			c[j]=s[i];
			
			i++;
		}
		j++;
	}	
	
	printf("\n按总分排序结果为：\n");

	k=m=0;
	
	for(i=0;i<j;i++)
	{
		for(p=0;p<n;p++)
		{
			if(c[i]==stu[p].sum)
			{
				k++;
				
				if(m==0)
					t=i+1;
					
				else
				{
					t=k;
				} 
				
				printf("\n %d. 学生学号：%s",t,stu[p].studentID);
		
				printf("\n    学生姓名：%s",stu[p].studentName);
				
				//printf("\n   英语成绩：%d",stu[p].score[0]);
				
				//printf("\n   数学成绩：%d",stu[p].score[1]);
				
				printf("\n     总分   ：%d\n\n",stu[p].sum);
				
				m=0;
			}
		}
		
		m=1;
	}		
} 
 
 
