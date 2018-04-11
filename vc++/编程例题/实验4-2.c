#include <stdio.h>
#include <stdlib.h>
#define ERROR 0;
struct link *AppendNode(struct link *head);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);

struct students
{
	char name[20];
	int wages;
	int age;
};

struct link
{
	struct students data;
	struct link *next;
};

int main()
{
	int i;
	struct link *head=NULL;
	head=AppendNode(head);
	DisplyNode(head);
	DeleteMemory(head);
}

struct link *AppendNode(struct link *head)
{
	struct link *p,*pr;
		if (!(head=(struct link*)malloc(sizeof(struct link)))){
			return ERROR;
		}
    head->next=NULL;
    pr=head;
    int i=0;
    for(;i<5;i++){
    	if (!(p=(struct link*)malloc(sizeof(struct link)))){
			return ERROR;
		}
	    printf("请输入第%d个员工的姓名\n",i+1);
	    scanf("%s",p->data.name);
	    getchar();
	    printf("请输入第%d个员工的工资\n",i+1);
	    scanf("%d",&(p->data.wages));
	    getchar();
	    printf("请输入第%d个员工的年龄\n",i+1);
	    scanf("%d",&(p->data.age));
	    getchar(); 
    	p->next=NULL;
    	pr->next=p;
    	pr=p;
    }
    return head;
}

void DisplyNode(struct link *head)
{
	struct link *p=NULL;
	int i;
	p=head->next;
	printf("姓名\t工资\t年龄\n");
	for(i=0;p!=NULL;i++)
	{
		printf("%s\t%d\t%d\t",p->data.name,(p->data.wages),(p->data.age));
		printf("\n");
		p=p->next;
	}
}

void DeleteMemory(struct link *head)
{
	struct link *p=head,*pr=NULL;
	while(p!=NULL){
		pr=p;
		p=p->next;
		free(pr);
	}
}
