//#include<malloc.h> // malloc()��
#include<limits.h> // INT_MAX��
#include<stdio.h> // EOF(=^Z��F6),NULL
#include<stdlib.h> // atoi()
//#include<io.h> // eof()
//#include<math.h> // floor(),ceil(),abs()
#include<process.h> // exit()
//#include<iostream.h> // cout,cin
#define INFINITY INT_MAX //���ֵ
#define MAX_VERTEX_NUM 20
#define OK 1
//#define MAX_NAME 5
typedef int VRType;
typedef int Status;
typedef char InfoType;
typedef char VertexType;
typedef enum{DG=1,DN=2,UDG=3,UDN=4} GraphKind;
typedef struct ArcCell
{
	VRType adj;//Vrtype �Ƕ����ϵ���͡�����Ȩͼ����1��0
			   //��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ����
	InfoType *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
	GraphKind kind;
}MGraph;
int CreateUDN(MGraph G);
Status CreateDN(MGraph G){
	return 0;
}
Status CreateDG(MGraph G){
	return 0;
}
Status CreateUDG(MGraph G){
	return 0;
}

//LocateVex
int LocateVex(MGraph G,int V)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.vexs[i]==V)
		return i;
	}
	return -1;
}

//���ͼ�ĺ���
void Print(MGraph G)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			printf("%d  ",G.arcs[i][j].adj);
		printf("\n");
	}
}

//��������ͼ
Status CreateUDN(MGraph G)
{
	int i,j,k,v1,v2,w;
	printf("�����붥�㣬��\n");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	printf("�����붥����Ϣ��\n");
	for(i=0;i<G.vexnum;++i)
		scanf("%d",&G.vexs[i]);
	for(i=0;i<G.vexnum;++i)
	{
		for(j=0;j<G.vexnum;++j)
		{
			G.arcs[i][j].adj=INFINITY;
			G.arcs[i][i].adj=NULL;
		}
	}
	for(k=0;k<G.arcnum;++k)
	{
		printf("������һ���������Ķ��㼰Ȩֵ\n");
		scanf("%d%d%d",&v1,&v2,&w);
		i=LocateVex(G,v1);  
		j=LocateVex(G,v2);
		G.arcs[i][j].adj=w;
		G.arcs[j][i].adj=w;
		//if(IncInfo) Input(*G.arcs[i][j].info);
		//G.arcs[j][i]=G.arcs[i][j];
	}
	Print(G);
	return OK;
}


//�ж�ͼ������
int CreateGraph(MGraph G)
{
	printf("������ͼ�����ͣ� DG:1,DN:2,UDG:3,UDN:4  \n");
	scanf("%d",&G.kind);
	switch(G.kind)
	{
	case 1:return CreateDG(G);//��������ͼG
		 
	case 2:return CreateDN(G);//����������G

	case 3:return CreateUDG(G);//��������ͼG
	   
	case 4:return CreateUDN(G);//����������G
	     
	}
	return 0;
}
int main()
{
	MGraph G;
	CreateGraph(G);
	return 0;
}
