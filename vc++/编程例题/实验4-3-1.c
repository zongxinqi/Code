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
	
	printf("\n������ѧ��������");
 	
 	scanf("%d",&n);
 	
	Input(n);
	
	printf("\n������m��ֵ��0�������Ӣ��ƽ���ɼ���1���������ѧƽ���ɼ�����",&ch);
	
	scanf("%d",&ch);
	
	Sort(ch,n);
	
	/*printf("\n������m��ֵ��0�������Ӣ��ƽ���ɼ���1���������ѧƽ���ɼ�����",&ch);
	 
	scanf("%d",&ch);
	
	Sort(ch,n);*/ 
	
	system("pause");
	
	printf("\n\n��������Ӣ��ɼ�Ϊĳ��ֵ��ѧ����������Ӣ��ɼ���");
	
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
 		printf("\n\n�������%d��ѧ����ѧ�ţ�",i+1);
	
		scanf("%s",&stu[i].studentID);
		
		getchar();
		
		printf("\n�������%d��ѧ����������",i+1);	
		
		scanf("%s",stu[i].studentName);
		
		getchar();
	
		printf("\n�������%d��ѧ����Ӣ��ɼ���",i+1);
		
		scanf("%d",&stu[i].score[0]);
		
		printf("\n�������%d��ѧ������ѧ�ɼ���",i+1);
		
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

//	printf("\n\nӢ��ƽ����Ϊ��%.2f\n",stu[0].eaver);
	
//	printf("\n��ѧƽ����Ϊ��%.2f\n\n",stu[0].maver);

	
	
	getchar();

	system("pause");
	
	printf("\n�������ѧ����Ϣ��\n");

	for(i=0;i<n;i++)
	{
		ll=(float)stu[i].sum/2;
		
		printf("\n ѧ��ѧ�ţ�%s",stu[i].studentID);
		
		printf("\n ѧ��������%s",stu[i].studentName);
		
		printf("\n Ӣ��ɼ���%d",stu[i].score[0]);
		
		printf("\n ��ѧ�ɼ���%d",stu[i].score[1]);
		
		printf("\n   ƽ���֣�%.2f\n",ll);
		
		printf("\n   �ܷ�  ��%d\n",stu[i].sum);
		
		getchar();
		
	//	system("pause");
	}
}
 
 void Sort(int m,int n)
 {
 	int i;
 	
 	if(m==0)
 	{
		printf("\nӢ��ƽ����Ϊ��%.2f\n",stu[0].eaver);
 		
 		printf("\n����Ӣ��ƽ���ֵ�ѧ����ϢΪ��\n");
 		
 		for(i=0;i<n;i++)
 		{
 			if(stu[i].score[0]<stu[0].eaver)
 			{
 				printf("\n ѧ��ѧ�ţ�%s",stu[i].studentID);
		
				printf("\n ѧ��������%s",stu[i].studentName);
				
				printf("\n Ӣ��ɼ���%d",stu[i].score[0]);
				
				printf("\n ��ѧ�ɼ���%d",stu[i].score[1]);
				
				printf("\n   �ܷ�  ��%d\n\n",stu[i].sum);
			 } 
		 }
	 }
	 
	 else if(m==1)
	 {
		printf("\n��ѧƽ����Ϊ��%.2f\n",stu[0].maver);
		
	 	printf("\n������ѧƽ���ֵ�ѧ����ϢΪ��\n");
	 	
	 	for(i=0;i<n;i++)
 		{
 			if(stu[i].score[1]<stu[0].maver)
 			{
 				printf("\n ѧ��ѧ�ţ�%s",stu[i].studentID);
		
				printf("\n ѧ��������%s",stu[i].studentName);
				
				printf("\n Ӣ��ɼ���%d",stu[i].score[0]);
				
				printf("\n ��ѧ�ɼ���%d",stu[i].score[1]);
				
				printf("\n   �ܷ�  ��%d\n\n",stu[i].sum);
			 }	
		 }
	 }
	 
	 else
	 {
	 	printf("\n n��ֵΪ0��1.\n");
	  } 
 }
 
 void Search(int m,int n)
 {
 	int i,j=0;
 	
 	for(i=0;i<n;i++)
 	{
 		if(m==stu[i].score[0])
 		{
			printf("\nӢ��ɼ�Ϊ%d��ѧ����ϢΪ��\n",m); 
			
			j=1;
			
			break;
		 }
	 }
	 
	if(j==0)
	{
	 	printf("û�иóɼ���ѧ����"); 
	}
	 
	else
	{
	 	for(i=0;i<n;i++)
		{
			if(m==stu[i].score[0])
			{
			 	printf("\n ѧ��ѧ�ţ�%s",stu[i].studentID);
		
				printf("\n ѧ��������%s",stu[i].studentName);
				
				printf("\n Ӣ��ɼ���%d",stu[i].score[0]);
				
				printf("\n ��ѧ�ɼ���%d",stu[i].score[1]);
				
				printf("\n   �ܷ�  ��%d\n\n",stu[i].sum);	
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
	
	printf("\n���ܷ�������Ϊ��\n");

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
				
				printf("\n %d. ѧ��ѧ�ţ�%s",t,stu[p].studentID);
		
				printf("\n    ѧ��������%s",stu[p].studentName);
				
				//printf("\n   Ӣ��ɼ���%d",stu[p].score[0]);
				
				//printf("\n   ��ѧ�ɼ���%d",stu[p].score[1]);
				
				printf("\n     �ܷ�   ��%d\n\n",stu[p].sum);
				
				m=0;
			}
		}
		
		m=1;
	}		
} 
 
 
