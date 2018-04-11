/*程序功能：根据积分将参赛队伍进行排序并输出 
编程者：宗新淇
编程时间：2017-10-16 16:14:54
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
//定义程序中需要的宏
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LISTINCREMENT 10

//定义程序中用到的数据类型别称
typedef  int Status ;

typedef struct footballTeam
{	char footballname;
	int all,win,equ,lose,GA,GF,sum;
}ElemType;

//定义单链表中结点的结构
struct LNode{
	ElemType data;
	struct LNode * next;
};

//对结点及结点指针类型进行重定义，目的是增强程序可读性
typedef struct LNode LNode;
typedef LNode* LinkList;
typedef LinkList Polynomial;


//对单链表操作的声明：
//初始化单链表
Status InitList_L(LinkList &L);

//获得单链表L中第i个位置处的元素，并将之存储到e中
Status GetElem_L(LinkList L, int i, ElemType &e);

//在链表L的第i个位置前插入元素e
Status ListInsert_L(LinkList &L, int i, ElemType e);

//创建多项链表 
void CreateTeam(Polynomial &lp,int n);

//输出链表中的数据 
void PrintTeam(Polynomial lp);

//将链表的数据进行排序
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

	p=L;	  //p初始指向头结点
	j = 0;     // j表示前结点在表中的位置，初值为0 

	//获得第i-1个元素的00地址
	while(p&&j<i-1)	
	{	p=p->next;	j++;}
	if(!p)	return ERROR;
	//在第i个元素前插入元素e
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
		printf("第%d支球队：", i);
		scanf("%d%d%d%d%d%d",&e.all,&e.win,&e.equ,&e.lose,&e.GF,&e.GA);
		ListInsert_L(lp,i,e);
	}
}


//输出多项式每一项的系数和指数的值
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

