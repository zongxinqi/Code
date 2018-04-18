struct link
{
	int data;
	struct link *next;/*指向下一个节点的地址*/ 
}
pr->next=NULL;
pr->next=p;
head=p->next;
free(p);/*释放p节点的地址*/
pr->next=p->next;
pr->next=NULL;/*插入和删除需要分头节点和中间节点*/
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
}/*链表的遍历：输出节点数和对应的数据*/
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


