#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#define N 21
using namespace std;
void gotoxy(int x,int y)//λ�ú���
{
COORD pos;
pos.X=2*x;
pos.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void color(int a)//��ɫ����
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void init(int apple[2])//��ʼ����������ʼ��Χǽ����ʾ��Ϣ��ƻ����
{
int i,j;//��ʼ��Χǽ
int wall[N+2][N+2]={{0}};
for(i=1;i<=N;i++)
{
for(j=1;j<=N;j++)
wall[i][j]=1;
}
color(11);
for(i=0;i<N+2;i++)
{
for(j=0;j<N+2;j++)
{
if(wall[i][j])
cout<<"��";
else cout<<"��" ;
}
cout<<endl;
}
gotoxy(N+3,1);//��ʾ��Ϣ
color(20);
cout<<"�� W S A D �ƶ�����"<<endl;
gotoxy(N+3,2);
color(20);
cout<<"���������ͣ"<<endl;
gotoxy(N+3,3);
color(20);
cout<<"�÷֣�"<<endl;
apple[0]=rand()%N+1;//ƻ��
apple[1]=rand()%N+1;
gotoxy(apple[0],apple[1]);
color(12);
cout<<"��"<<endl;
}
int main()
{
int i,j;
int** snake=NULL;
int apple[2];
int score=0;
int tail[2];
int len=3;
char ch='p';
srand((unsigned)time(NULL));
init(apple);
snake=(int**)realloc(snake,sizeof(int*)*len);
for(i=0;i<len;i++)
snake[i]=(int*)malloc(sizeof(int)*2);
for(i=0;i<len;i++)
{
snake[i][0]=N/2;
snake[i][1]=N/2+i;
gotoxy(snake[i][0],snake[i][1]);
color(14);
cout<<"��"<<endl;
}
while(1)//������Ϣѭ��
{
tail[0]=snake[len-1][0];
tail[1]=snake[len-1][1];
gotoxy(tail[0],tail[1]);
color(11);
cout<<"��"<<endl;
for(i=len-1;i>0;i--)
{
snake[i][0]=snake[i-1][0];
snake[i][1]=snake[i-1][1];
gotoxy(snake[i][0],snake[i][1]);
color(14);
cout<<"��"<<endl;
}
if(kbhit())
{
gotoxy(0,N+2);
ch=getche();
}
switch(ch)
{
case 'w':snake[0][1]--;break;
case 's':snake[0][1]++;break;
case 'a':snake[0][0]--;break;
case 'd':snake[0][0]++;break;
default: break;
}
gotoxy(snake[0][0],snake[0][1]);
color(14);
cout<<"��"<<endl;
Sleep(abs(200-0.5*score));
if(snake[0][0]==apple[0]&&snake[0][1]==apple[1])//�Ե�ƻ�����߷�����1���߳���1
{
score++;
len++;
snake=(int**)realloc(snake,sizeof(int*)*len);
snake[len-1]=(int*)malloc(sizeof(int)*2);
apple[0]=rand()%N+1;
apple[1]=rand()%N+1;
gotoxy(apple[0],apple[1]);
color(12);
cout<<"��"<<endl;
gotoxy(N+5,3);
color(20);
cout<<score<<endl;
}
if(snake[0][1]==0||snake[0][1]==N||snake[0][0]==0||snake[0][0]==N)//ײ��Χǽ��ʧ��
{
gotoxy(N/2,N/2);
color(30);
cout<<"ʧ�ܣ�����"<<endl;
for(i=0;i<len;i++)
free(snake[i]);
Sleep(INFINITE);
exit(0);
}
}
return 0;
}
