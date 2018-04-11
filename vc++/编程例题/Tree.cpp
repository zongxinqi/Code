#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode*LChild;
	struct BiTNode*RChild;
}BiTNode;

BiTNode*CreateTree()
{
	char a[10];
	int n,i;
	BiTNode*Tree;
	printf("请输入节点个数：\n");
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf(" %c",&a[i]);
	}
//	if(!strcmp("",a)) 
//	{
//		Tree = NULL;
//		return Tree;
//	}
		Tree = (BiTNode*)malloc(sizeof(BiTNode));
		Tree->data =  a[i];
		Tree->LChild = CreateTree();
		Tree->RChild = CreateTree();
		return Tree;
}

int print(BiTNode*Tree)
{
	if(Tree == NULL)
	{
		printf("Tree is NULL\n");
		return 0;
	}
	else 
	{
		printf("(");
		printf("%c ",Tree->data);
		if(Tree->LChild) print(Tree->LChild);
		else if(Tree->RChild) print(Tree->RChild);
		printf(")");
	}
}

int PreOrder(BiTNode*Tree)
{
	if(Tree)
	{
		printf("%c ",Tree->data);
		PreOrder(Tree->LChild);
		PreOrder(Tree->RChild);
	}
}

int MidOrder(BiTNode*Tree)
{
	if(Tree)
	{
		PreOrder(Tree->LChild);
		printf("%c ",Tree->data);
		PreOrder(Tree->RChild);
	}
}

int main()
{
	BiTNode*Tree;
	Tree = CreateTree();
	if(!Tree)
	printf("root is NULL\n");
	else
	{
		PreOrder(Tree);
		printf("\n");
		MidOrder(Tree);
		print(Tree);
	}
	return 0;
}

 
