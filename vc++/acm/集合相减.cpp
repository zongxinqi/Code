//#include<stdio.h>
//#include<math.h>
//int swap(int *x,int *y);
//int main()
//{
// 	int m,n,i,j,num[200],flag[100],count;
//	while(scanf("%d%d",&m,&n)&&m&&n)
//	{
//		for(i = 0;i < m+n;i++)
//		scanf("%d",&num[i]);
//		for(i = 0;i < m-1;i++)
//		{
//			for(j = i+1;j < m;j++)
//			if(num[i] > num[j]) swap(num+i,num+j);
//		}
//			count = 0;
//		for(i = 0;i < m;i ++)
//		{
//			flag[i] = 1;
//			for(j = m;j < m+n;j++)
//			{
//				if(num[i] == num[j])
//				{
//					flag[i] = 0;
//					break;
//				}
//			}
//			if(flag[i])	count++;
//		}
//		if(count==0) printf("NULL");
//		else
//		{
//			count = 0;
//			for(i = 0;i < m;i++)
//				{
//					if(flag[i]&&count == 0)
//					{
//						printf("%d",num[i]);
//						count = 1;
//					} 
//					else if(flag[i] == 1)  printf(" %d",num[i]);
//				}	
//		}
//		printf("\n");
//	}
//	return 0;	 
//} 
//
//int swap(int *x,int *y)
//{
//	int temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//	return 0;
//}

#include<iostream>
#include<algorithm>
using namespace std;

main()
{
	int i,m,n,flag,a[100],b[100],c[200] = {0};
	while(cin>>m>>n&&(m||n))
	{
		flag = 1;
		for(i = 0;i < m;i++)
		cin>>a[i];
		sort(a,m+a);
		for(int j = 0;j < n;j++)
		{
			cin>>b[j];
			{
				for(i = 0;i < m;i++)
				{
					if(b[j] == a[i])
					c[i] = 1;
				}
			}
		}
		for(i = 0;i < m;i++)
		{
			if(c[i]!=1) 
			{
				cout<<a[i]<<" ";flag = 0;
			}
		}
		if(flag) cout<<"NULL";
		cout<<endl;
	}
}
