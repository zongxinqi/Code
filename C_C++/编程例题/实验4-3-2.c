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
	
	printf("\n�����\n\n");
	
    output (head);
	
    Insert(head);
    
    printf("\n����ɹ���\n�����������ǣ�\n");
        
    output (head);

    printf("����Ҫɾ���Ľ�㣺");
    
    scanf("%d",&b);
    
	val=Del(head,b);
    
    if (val == 0)
    {
        printf("ɾ��ʧ�ܡ�\n");
    }
    else
    {
        printf("\nɾ���ɹ���\n");
    }
    printf("ɾ����ɺ�������ǣ�\n");
    
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
        
        printf("\n����������");
        
        scanf("%s",p->name);
        
        getchar();
        
        printf("�������䣺");
        
        scanf("%d",&p->age);
        
        printf("���빤�ʣ�");
        
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
        printf("������%s,���䣺%d,���ʣ�%.2f\n\n",pr->name,pr->age,pr->wages);
        
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
	    printf("������Ҫ���������ڵڼ����ڵ㣺");
    
    	scanf("%d",&num);
    	
    	if(num>0&&num<7)
	    {
	    	pnew = ( struct worker *)malloc(LEN);
	    		
	        printf("\n������Ҫ�����������");
	    
		    scanf("%s",pnew->name);
		    
		    printf("������Ҫ��������䣺");
		 
		    scanf("%d",&pnew->age);
		    
		    printf("������Ҫ����Ĺ��ʣ�");
		    
		    scanf("%f",&pnew->wages);

		    break;
		}
		
		else
		{
			printf("�������\n"); 
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

//    ɾ������ڵ㺯��
int Del(struct worker *head,int back)
{
    int i = 0,data;
    
    struct worker *pSwap,*pr, *p=NULL;
    
    pr = head;
    
    if ((back < 1) && (NULL == pr->next))
    {
        printf("ɾ��ʧ�ܣ�\n");
        
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
