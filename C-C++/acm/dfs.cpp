#include<stdio.h>
#include<string.h>
int prime[40]={0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0},n;//���������Ϊn�����20������ֻҪ��40
int visited[21],a[21];
void dfs(int num)//����
{
   int i;
   if(num==n&&prime[a[num-1]+a[0]])  //���������ˣ��������
   {
       for(i=0;i<num-1;i++)
           printf("%d ",a[i]);
       printf("%d\n",a[num-1]);
   }
   else
   {
       for(i=2;i<=n;i++)
       {
           if(visited[i]==0)//�Ƿ��ù���
           {
               if(prime[i+a[num-1]]) //�Ƿ�����ڵļ�����������
               {
                   visited[i]=-1;//�����
                   a[num++]=i;//�Ž�����
                   dfs(num); //�ݹ����
                   visited[i]=0; //��ȥ���
                   num--;
               }
           }
       }
   }
}    
int main()
{
      int num=0;
      while(scanf("%d",&n)!=EOF)
      {
         num++;
         printf("Case %d:\n",num);
         memset(visited,0,sizeof(visited));
         a[0]=1;
         dfs(1);
         printf("\n");
      }
      return 0;
}
