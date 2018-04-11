// porter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include "stdlib.h"
#include "conio.h"
#include<iostream>
#include "fstream.h"
const int size=100;

class dot
{
public:
 void setd(int a,int b)
 {
  x=a;
  y=b;
 }
 int x,y; 
};

void pri(char a[size][size],int mx,int my)
{
 for(int i=0;i<mx;i++)
 {
  for(int j=0;j<my;j++)
   cout<<a[i][j]<<flush;
  cout<<endl;
 }
}

void drawd(char a[size][size],dot *d,int maxd)
{
 for(int i=0;i<maxd;i++)
  if(a[d[i].x][d[i].y]==' ')a[d[i].x][d[i].y]='*';
}

bool win(char a[size][size],dot *d,int maxd)
{
 int count=0;
 for(int i=0;i<maxd;i++)
  if(a[d[i].x][d[i].y]=='O')count++;
 if(count==maxd)return true;
 return false;
}

void maperr(int t)
{
 if(t==1)cout<<"map out of range!"<<endl;
 if(t==0)cout<<"unknown character in map!"<<endl;
 system("pause");
 exit(0);
}

void main()
{
 cout<<"About:\n'$' is the porter\n'H' is the walls"<<endl;
 cout<<"'O' is the boxes\n'*' is the destinations"<<endl;
 cout<<"and what you should do is to push all the boxes to the destinations\n"<<endl;
 cout<<"'w'=up   'a'=left   's'=down   'd'=right\npress 'q' to quit anytime\n"<<endl;
 system("pause");
 char a[size][size];
 int rept,cur;
S: 
 ////////读取地图
 ifstream inf("map.txt");
 int mx=0,my=0,myy=0;
 char tmp;
 if(rept==1)
 {
  rept=0;
  inf.seekg(cur);
 }
 while(true)
 {
  tmp=inf.get();
  switch(tmp)
  {
  case 'H':
  case 'O':
  case '$':
  case '\n':
  case ' ':
  case '*':
  case '!':
  case '@':

              break;
  default:maperr(0);
  }
  if(tmp=='@')break;
  if(tmp=='!')
  {
   rept=1;
   inf.get();
   cur=inf.tellg();
   break;
  }
  if(tmp=='\n')
  {
   mx++;
   myy=0;
   if(mx>size)maperr(1);
   continue;
  }
  a[mx][myy++]=tmp;
  if(myy>size)maperr(1);
  if(myy>my)my=myy;
 }
 mx++;
 ////////获取初始参数
 int maxd=0,x,y;
 dot d[20];
 for(int j=0;j<size;j++)
  for(int k=0;k<size;k++)
  {
   if(a[j][k]=='*')d[maxd++].setd(j,k);
   if(a[j][k]=='$')
   {
    x=j;
    y=k;
   }
  }
 ///////行走过程
 int i=0,count=0;
 char c,pre=' ';
 while(!win(a,d,maxd))
 {
  system("cls");
  pri(a,mx,my);
  c=getch();
  switch(c)
  {
  case 'w':
   if(a[x-1][y]=='H')continue;
   if(a[x-1][y]=='O')
   {
    if(a[x-2][y]=='H'||a[x-2][y]=='O')continue;
    a[x-2][y]='O';
   }
   a[x][y]=pre;x--;break;
  case 'a':
   if(a[x][y-1]=='H')continue;
   if(a[x][y-1]=='O')
   {
    if(a[x][y-2]=='H'||a[x][y-2]=='O')continue;
    a[x][y-2]='O';
   }
   a[x][y]=pre;y--;break;
  case 's':
   if(a[x+1][y]=='H')continue;
   if(a[x+1][y]=='O')
   {
    if(a[x+2][y]=='H'||a[x+2][y]=='O')continue;
    a[x+2][y]='O';
   }
   a[x][y]=pre;x++;break;
  case 'd':
   if(a[x][y+1]=='H')continue;
   if(a[x][y+1]=='O')
   {
    if(a[x][y+2]=='H'||a[x][y+2]=='O')continue;
    a[x][y+2]='O';
   }
   a[x][y]=pre;y++;break;
  case 'q':exit(0);
  default:;
  }
  count++;
  pre=a[x][y];
  if(pre=='O'||pre=='$')pre=' ';
  drawd(a,d,maxd);
  a[x][y]='$';
 }
 system("cls");
 pri(a,mx,my);
 ////////赢了
 cout<<"Well Done!\nYou run "<<count<<" steps"<<endl;
 system("pause");
 if(rept==1)goto S;
}
