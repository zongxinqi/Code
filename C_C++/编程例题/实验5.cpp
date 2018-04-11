/*�����ܣ����ݻ��ֽ������������������� 
����ߣ������
���ʱ�䣺2017-10-16 16:14:54
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
//�����������Ҫ�ĺ�
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LISTINCREMENT 10

//����������õ����������ͱ��
typedef  int Status ;

typedef struct footballTeam
{	char footballname;
	int all,win,equ,lose,GA,GF,sum;
}ElemType;

//���嵥�����н��Ľṹ
struct LNode{
	ElemType data;
	struct LNode * next;
};

//�Խ�㼰���ָ�����ͽ����ض��壬Ŀ������ǿ����ɶ���
typedef struct LNode LNode;
typedef LNode* LinkList;
typedef LinkList Polynomial;


//�Ե����������������
//��ʼ��������
Status InitList_L(LinkList &L);

//��õ�����L�е�i��λ�ô���Ԫ�أ�����֮�洢��e��
Status GetElem_L(LinkList L, int i, ElemType &e);

//������L�ĵ�i��λ��ǰ����Ԫ��e
Status ListInsert_L(LinkList &L, int i, ElemType e);

//������������ 
void CreateTeam(Polynomial &lp,int n);

//��������е����� 
void PrintTeam(Polynomial lp);

//����������ݽ�������
void Datasort(Polynomial lp,int n);

int main()
{
	Polynomial lp;
	int n;
	printf("please input the number of footballTeams:");
	scanf("%d",&n);
	CreateTeam(lp,n);
	PrintTeam(lp);
	return 0;
}


Status InitList_L(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL)	exit(OVERFLOW);
	L->next = NULL;
	return OK;
}


int ListLength_L(LinkList L)
{
	LNode *p = L->next ;
	int num = 0;
	while(p != NULL)
	{
		num++;
		p = p->next;
	}
	return num;
}

Status GetElem_L(LinkList L, int i, ElemType &e)
{
	LNode *p = L->next ;
	int j = 1;
	
	while(p != NULL && j<i)
	{
		j++;
		p = p->next ;
	}
	if(p == NULL)	return ERROR;
	else e =  p->data;
	return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e)
{
	LNode *p,*s;
	int j ;

	p=L;	  //p��ʼָ��ͷ���
	j = 0;     // j��ʾǰ����ڱ��е�λ�ã���ֵΪ0 

	//��õ�i-1��Ԫ�ص�00��ַ
	while(p&&j<i-1)	
	{	p=p->next;	j++;}
	if(!p)	return ERROR;
	//�ڵ�i��Ԫ��ǰ����Ԫ��e
	else	
	{
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;	
	s->next=p->next;	p->next=s;
	}
	return  OK;

}


void CreateTeam(Polynomial &lp, int n)
{
	ElemType e;
	int i;

	InitList_L(lp);
	
	for(i=1; i<=n; i++)
	{
		printf("��%d֧��ӣ�", i);
		scanf("%d%d%d%d%d%d",&e.all,&e.win,&e.equ,&e.lose,&e.GF,&e.GA);
		ListInsert_L(lp,i,e);
	}
}


//�������ʽÿһ���ϵ����ָ����ֵ
void PrintTeam(Polynomial lp)
{
	ElemType e;
	LNode * p = lp->next  ;
	printf("           all\twin\tequ\tlose\tGF\tGA\tsum\n");
	while(p)
	{
		e = p->data;
		printf("           %d\t%d\t%d\t%d\t%d\t%d\t%d\n",e.all,e.win,e.equ,e.lose,e.GF,e.GA,e.sum);
		p = p->next ;
	}
}


void Datasort(Polynomial lp,int n)
{
	ElemType p;
    int i = 0;
    for(i = 0;i < n;i++)
    {
    	if(GetElem_L(L,i,e).win*3 + GetElem_L(L,i,e).equ < GetElem_L(L,i+1,e).win*3 + GetElem_L(L,i+1,e).equ)
    
    else if(GetElem_L(L,i,e).win*3 + GetElem_L(L,i,e).equ = GetElem_L(L,i+1,e).win*3 + GetElem_L(L,i+1,e).equ)
    {
    	if(GetElem_L(L,i,e).GF)
	}
	}
}

