struct link
{
	int data;
	struct link *next;/*ָ����һ���ڵ�ĵ�ַ*/ 
}
pr->next=NULL;
pr->next=p;
head=p->next;
free(p);/*�ͷ�p�ڵ�ĵ�ַ*/
pr->next=p->next;
pr->next=NULL;/*�����ɾ����Ҫ��ͷ�ڵ���м�ڵ�*/
head=p;
p=(struct link*)malloc(sizeof(struct link));
p->next=NULL; 
struct link*p=head;
int j=1;
while(p!=NULL)
{
	printf("%d%d",j,p->data);
	p=p->next;
	j++;
}/*����ı���������ڵ����Ͷ�Ӧ������*/
head=&a;
a.next=&b;
b.next=NULL;
struct student 
{
	float score;
	long num;
	struct student *next;
}
p2=p1;
p1=scanf
p2->next =p1;


