#include<stdio.h>     
#include <stdlib.h>    
#define OK 1;
#define ERROR 0;
//���һ�����ݺ�ָ����һ���ڵ��ָ��   
typedef struct LNode 
{
	int data;
	struct LNode* next;
}LNode;
//����һ���������ڵ㸳ֵ1~n 
LNode *CreateList_L(int n)
{
	LNode *p,*q,*h;
	int i;
	//�ж��Ƿ����ڵ�ɹ� 
	if(!(p=(LNode*)malloc(sizeof(LNode))))
	{
		return ERROR;
	}
	h=p;
	p->data=1;
	//��ֵ 
	for(i=2;i<=n;i++)
	{		
		if(!(q=(LNode*)malloc(sizeof(LNode))))
		{
			return ERROR;
		}
		q->data=i;
		p->next=q;
		p=q;
	}
	//ָ��ͷ��� 
	p->next=h;
	return h;	
} 
void Select_M(LNode*h,int x,int m,int n)
{
	int i;
	LNode*p=h,*temp;
	//�ж��Ƿ�m=1 
	if(m==1)
	{
		while(p->data!=x)
		{
			temp=p;
			p=p->next;
		}
		for(i=1;i<=n;i++)
		{
			temp=p;
			p=p->next;
		printf("%d ",temp->data);
		}
	} 
 //��ָ��ָ����һ�������� 
	while(p->data!=x)
	{
		temp=p;
		p=p->next;
	}
	//�ӵ�һ�������˿�ʼ�ж� 
	while (p->next!=p)
	{
		for(i=1;i<m;i++)
		{
			temp=p;
			p=p->next;
		}
		printf("%d ",p->data);
		//����������ˣ�ָ����һ�� 
		temp->next=p->next; 
		free(p);
		p=temp->next;
	}
	//������һ�� 
	printf("%d ",p->data);
	free(p);
	
}
int main()
{
	int n,x,m;
	printf("�������ܹ�������:");
	scanf("%d",&n); 	
	printf("������ӵڼ����˿�ʼ����:");
	scanf("%d",&x); 
	printf("������Ҫ��������:");
	scanf("%d",&m); 
	LNode *h=CreateList_L(n);
	Select_M(h,x,m,n);
	return 0;
}
