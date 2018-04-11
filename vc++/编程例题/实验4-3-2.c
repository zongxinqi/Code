#include <stdio.h>

#include <stdlib.h>

#include <malloc.h>

#define LEN sizeof(struct  worker)

struct worker *creat();

void output( struct worker *head );

void Insert(struct worker *head);

int Del(struct worker *head,int back);

struct  worker
{  
    char name[20];
    
    int age;
    
    float wages;
    
    struct worker *next;

}stu[5];

int main()
{ 
    struct worker *head=NULL;
    
    int b,val,i=0;
    
    char n[20];
    
    int ag;
    
    float wag;
       
	head=creat();
	
	printf("\n输出：\n\n");
	
    output (head);
	
    Insert(head);
    
    printf("\n插入成功。\n插入后的数据是：\n");
        
    output (head);

    printf("输入要删除的结点：");
    
    scanf("%d",&b);
    
	val=Del(head,b);
    
    if (val == 0)
    {
        printf("删除失败。\n");
    }
    else
    {
        printf("\n删除成功。\n");
    }
    printf("删除完成后的数据是：\n");
    
    output (head);
    
	return 0;
 }
 
struct worker *creat()
{
    int i,n;
    
    int wages;
    
    struct worker *head;
    
    struct worker *pr, *p=NULL;
    
    n = 0;
    
    head = pr = ( struct worker *)malloc(LEN);
    
   // head->next = NULL;
    
    for ( i = 0; i <5; i++ )
    {
        p = ( struct worker *)malloc(LEN);
        
        printf("\n输入姓名：");
        
        scanf("%s",p->name);
        
        getchar();
        
        printf("输入年龄：");
        
        scanf("%d",&p->age);
        
        printf("输入工资：");
        
        scanf("%f",&p->wages);
        
        n++;
        
        pr->next = p;
        
        pr = p;
    }
    p->next = NULL;
    
    head->age = n;
    
    return(head);
}

void output( struct worker *head )
{
    struct worker *pr;
    
    int i = 1;
    
    pr = head->next;
    
    do
    {
        printf("姓名：%s,年龄：%d,工资：%.2f\n\n",pr->name,pr->age,pr->wages);
        
        pr = pr->next;
        
        i++;
        
    }while ( pr != NULL );
}

void Insert(struct worker *head)
{
    int num,i;

    struct worker *pSwap,*pr, *pnew;
    
    pr = head;
    
    for(i=0;i<5;i++)
    {
	    printf("请输入要插入数据在第几个节点：");
    
    	scanf("%d",&num);
    	
    	if(num>0&&num<7)
	    {
	    	pnew = ( struct worker *)malloc(LEN);
	    		
	        printf("\n请输入要插入的姓名：");
	    
		    scanf("%s",pnew->name);
		    
		    printf("请输入要插入的年龄：");
		 
		    scanf("%d",&pnew->age);
		    
		    printf("请输入要插入的工资：");
		    
		    scanf("%f",&pnew->wages);

		    break;
		}
		
		else
		{
			printf("输入错误。\n"); 
		}
    
	}
	
	i=0;
	
    while (i < num-1)    
    {
        pr = pr->next;
        
        ++i;
    }	
	                 
    pSwap = pr->next;
	                       
    pr->next = pnew; 
	                  
    pnew->next = pSwap; 
}

//    删除链表节点函数
int Del(struct worker *head,int back)
{
    int i = 0,data;
    
    struct worker *pSwap,*pr, *p=NULL;
    
    pr = head;
    
    if ((back < 1) && (NULL == pr->next))
    {
        printf("删除失败！\n");
        
        return 0;
    }
    while(i < back-1)
    {
        pr = pr->next;
        
        ++i;
    }
    
    pSwap = pr->next;
    
    data= pSwap->age;
    
    pr->next = pr->next->next;
    
    free(pSwap);
    
   return data;
} 
