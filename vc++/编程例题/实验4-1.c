#include<stdio.h>     
#include <stdlib.h>    
#define OK 1;
#define ERROR 0;
//存放一个数据和指向下一个节点的指针   
typedef struct LNode 
{
	int data;
	struct LNode* next;
}LNode;
//创建一个链表并给节点赋值1~n 
LNode *CreateList_L(int n)
{
	LNode *p,*q,*h;
	int i;
	//判断是否分配节点成功 
	if(!(p=(LNode*)malloc(sizeof(LNode))))
	{
		return ERROR;
	}
	h=p;
	p->data=1;
	//赋值 
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
	//指向头结点 
	p->next=h;
	return h;	
} 
void Select_M(LNode*h,int x,int m,int n)
{
	int i;
	LNode*p=h,*temp;
	//判断是否m=1 
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
 //将指针指到第一个报数人 
	while(p->data!=x)
	{
		temp=p;
		p=p->next;
	}
	//从第一个报数人开始判断 
	while (p->next!=p)
	{
		for(i=1;i<m;i++)
		{
			temp=p;
			p=p->next;
		}
		printf("%d ",p->data);
		//跳过输出的人，指向下一个 
		temp->next=p->next; 
		free(p);
		p=temp->next;
	}
	//输出最后一个 
	printf("%d ",p->data);
	free(p);
	
}
int main()
{
	int n,x,m;
	printf("请输入总共几个人:");
	scanf("%d",&n); 	
	printf("请输入从第几个人开始报数:");
	scanf("%d",&x); 
	printf("请输入要报几个数:");
	scanf("%d",&m); 
	LNode *h=CreateList_L(n);
	Select_M(h,x,m,n);
	return 0;
}
